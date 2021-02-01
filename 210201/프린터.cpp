#include <queue>
#include <vector>
using namespace std;

// 4분 ~ 24분
// 시간복잡도 : O(N^2)
int solution(vector<int> priorities, int location) {
    int answer=0;
    // 현재 남아있는 대기 목록 중 먼저 뽑혀야할 중요도를 알아내기 위한 최대힙
    priority_queue<int> pq;
    for(auto &k:priorities)
        pq.push(k);
    // 맨 앞에서 꺼내고, 맨 뒤로 push하기 위해 deque 사용
    deque<pair<int,int>>dq;
    for(int i=0;i<priorities.size();i++){
        dq.push_back({i,priorities[i]});
    }
    while(1){
        // 현재 대기 목록 가장 앞에 있는 문서
        int idx=dq.front().first;
        int pri = dq.front().second;
        // 제일 첫번째 우선순위가 아니면(나머지 인쇄 대기목록에서 J보다 중요도가 높은 문서가 있다면)
        dq.pop_front();
        if(pri!=pq.top()){
            // 인쇄하지 않음(뒤로 보냄)
            dq.push_back({idx,pri});
        }
        // 우선순위가 맞으면 인쇄
        else{
            pq.pop();
            answer++;
            // 요청한 문서일 경우 return
            if(idx==location)
                return answer;
        }
    }
}