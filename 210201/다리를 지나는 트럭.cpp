#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 40분 ~ 5분 (25분)

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx=0;
    int sum=0;
    int finished=0;
    deque<pair<int,int>>bridge;
    while(1){
        answer++;
        // dq에 있는 값들 모두 한칸씩 움직이기
        for(int i=0;i<bridge.size();i++){
            bridge[i].first++;
        }
        // 맨 첫 칸 도착지에 도착했으면 내리기
        if(!bridge.empty() && bridge[0].first==bridge_length){
            finished++;
            sum-=bridge[0].second;
            bridge.pop_front();
            if(finished==truck_weights.size())
                return answer;
        }
        // 새로운 애 태울 수 있으면 태우기
        if(bridge.size()<bridge_length && sum+truck_weights[idx]<=weight){
            bridge.push_back({0,truck_weights[idx]});
            sum+=truck_weights[idx];
            idx++;
        } 
    }
}