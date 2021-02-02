#include <string>
#include <vector>
#include <queue>
using namespace std;
// 17분
// 26분
queue<int> q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        // 작업 완료를 위해 필요한 일수 계산해서 queue에 넣어줌
        int days = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i]!=0)
            days++;
        q.push(days);
    }
    while(!q.empty()){
        // 맨 앞에서부터 순서대로 배포하기 위해 queue를 사용 (FIFO)
        int cur = q.front();
        int cnt=1;
        q.pop();
        // 해당 기능이 배포될 때 함께 배포 될 수 있는 기능 개수 count
        while(!q.empty() && q.front()<=cur){
            cnt++;
            q.pop();
        }
        answer.push_back(cnt);
    }
    return answer;
}