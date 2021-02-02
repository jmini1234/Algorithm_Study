#include <bits/stdc++.h>
 
using namespace std;
 
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, cw = 0;
    queue<int> count, bridge;
	//truck_weights :대기 트럭, bridge : 다리를 건너는 트럭의 남은 거리, cw : 다리 위 트럭의 무게
	//count : 다리를 건너는 트럭의 인덱스
    while (1) {
        int size = bridge.size();
        for (int i = 0; i < size; i++){
            int length = bridge.front();
            bridge.pop();
			//남은 거리가 1이하이면 큐에서 뺌
            if (length <= 1) {
                cw -= count.front();
                count.pop();
            }
			//2이상이면 1 감소시켜서 큐에 저장
            else bridge.push(length - 1);
        }
		//대기하는 트럭이 있고 맨 앞의 트럭이 다리 위에 올라갈 수 있으면
        if (truck_weights.size() && cw + truck_weights.at(0) <= weight) {
            //트럭 인덱스 큐에 넣기
			count.push(truck_weights.at(0));
            //현재 무게 증가
			cw += truck_weights.at(0);
            //다리 길이만큼 남은 시간 큐에 저장
			bridge.push(bridge_length);
			//대기열에 맨 앞 트럭 삭제
            truck_weights.erase(truck_weights.begin());
        }
		//1초 증가
        answer++;
		//대기하는 트럭과 다리를 건너는 트럭이 하나도 없을 때 루프 중단
        if (!truck_weights.size() && !count.size()) break;
    }
    return answer;
}