#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    // 가장 큰 값과 딱 limit에 맞는 무게를 꺼낼 필요 없다. 
    // 가장 작은 값만 확인해주면 된다. 
    // 또는 이분탐색으로 진행
    deque<int>dq(people.begin(),people.end());
    sort(dq.begin(),dq.end());
    while(!dq.empty()){
        int back = dq.back();
        dq.pop_back();
        answer++;
        if(!dq.empty() && dq.front()+back<=limit)
            dq.pop_front();
    }
    
    return answer;
}