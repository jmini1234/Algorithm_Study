#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int cnt,day;
    vector<int> answer;
    queue<int> q;
    //걸리는 일 수 계산
    for(int i=0;i<progresses.size();i++){
        int d = 100-progresses[i];
        d= d%speeds[i]? d/speeds[i]+1:d/speeds[i];
        q.push(d);
    }
      
    while(q.size()){
        int front = q.front();
        q.pop();
        cnt =1;
        int size = q.size();
        
        for(int i=0;i<size;i++){
			//뒤에 있는 기능이 같이 배포될 수 없으면
            if(front<q.front()) {
                break;
            }
            else {
                q.pop();
                cnt++;
            }
        }        
        answer.push_back(cnt);
    }
    return answer;
}