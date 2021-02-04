#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int,vector<int>,greater<int>>pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(auto &k:scoville)
        pq.push(k);
    
    bool flag=true;
    while(1){
        // 가장 작은 수가 K를 넘으면 모두 만족하는 조건
        if(pq.top()>=K)
            break;
        // 가장 작은 수가 K를 넘지 않으면서 크기가 1이면 더이상 계산 진행 불가
        else if(pq.size()==1){
            flag=false;
            break;
        }
        int n1 = pq.top(); pq.pop();
        int n2 = pq.top(); pq.pop();
        pq.push(n1+n2*2);
        answer++;
    }
    
    if(!flag)
        answer=-1;
    
    return answer;
}