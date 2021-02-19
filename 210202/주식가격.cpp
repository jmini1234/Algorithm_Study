#include<cmath>
#include<iostream>
#include <string>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include <cstring>

using namespace std;
// 16분
int t;
bool visited[10001] = { false, };
int a, b;

// 2 4 8 16
// 2 4 8 

int changeNum(int intNum, int idx) {
	if (idx == 1) {
		return 2 * intNum % 10000;
	}
	else if (idx == 2) {
		if (intNum == 0)
			return 9999;
		else
			return intNum - 1;
	}
	// R 오른쪽으로 옮기기
	else if (idx == 3) {
		int lastNum = intNum % 10;
		intNum /= 10;
		return lastNum * 1000 + intNum;
	}
	else {
		int first = intNum / 1000;
		intNum -= frist * 1000;
		return first + intNum * 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	// 현재 값, 명령어가 차례대로 저장
	while (t--) {
		memset(visited, false, sizeof(visited));
		queue<pair<string, string>>q;
		cin >> a >> b;
		visited[a] = true;
		// 무조건 BFS... 
		// 하지만 명령어 나열 어케하지 .. (queue에 string으로 저장)
		q.push({ a,"" });
		while (!q.empty()) {
			int cur = q.front().first;
			int cmp = q.front().second;
			q.pop();
			if (cur == b) {
				cout << cmp << endl;
				break;
			}
			// 4가지 결과
			for (int k = 1; k <= 4; k++) {
				int changed = changeNum(cur, k);
				if (changed<10000 && !visited[changed]) {
					visited[changed] = true;
					char ch;
					if (k == 1) ch = 'D';
					if (k == 2) ch = 'S';
					if (k == 3) ch = 'L';
					if (k == 4) ch = 'R';
					if (changed == b) {
						cout << cmp + ch << endl;
						break;
					}
					q.push({ changed,cmp + ch });
				}
			}
		}

	}

}