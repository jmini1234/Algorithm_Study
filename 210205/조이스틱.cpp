#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 34분

bool visited[21] = { false, };
int cnt[21] = { 0, };

bool IsEnd() {
	for (int i = 0; i<21; i++)
		if (cnt[i] != 0)
			return false;
	return true;
}

int solution(string name) {
	int answer = 0;
    
	for (int i = 0; i<name.size(); i++) {
		int gap = name[i] - 'A';
        // 시작 문자열에서 위 아래로 최소 움직이는 횟수 저장
		cnt[i] = min(gap, 26 - gap);
	}
    int idx=0;
	while(!IsEnd()) {
		// 현재 위치에서 아직 변하지 않은 알파벳을 오른쪽으로 찾아감 
		int right = idx;
		int right_cnt = 0;
		while (cnt[right] == 0) {
			right = (right + 1) % name.size();
			right_cnt++;
		}
        // 현재 위치에서 아직 변하지 않은 알파벳을 왼쪽으로 찾아감 
		int left = idx;
		int left_cnt = 0;
		while (cnt[left] == 0) {
            // 인덱싱 처리 주의 !
			left = (left + name.size() - 1) % name.size();
			left_cnt++;
		}
        // 오른쪽으로 이동하는게 더 가까울 때
		if (right_cnt <=left_cnt) {
			idx = right;
			answer += right_cnt;
		}
		else {
			idx = left;
			answer += left_cnt;
		}
		answer += cnt[idx];
		cnt[idx] = 0;
	}

	return answer;
}