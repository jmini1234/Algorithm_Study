#include <bits/stdc++.h>

using namespace std;
queue<pair<int,int>> q;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0;i<priorities.size();i++){
       q.push({i,priorities[i]});
       pq.push(priorities[i]);
    }
    while(!pq.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        //우선순위가 가장 높으면서
        if(b == pq.top()){
            answer++;
            pq.pop();
            //요청한 문서이면 끝
            if(a == location) break;
        }
		//문서의 우선수위가 최우선이 아니면 큐에 다시 넣기
        else{
            q.push({a,b});
        }
    }
    return answer;
    
}