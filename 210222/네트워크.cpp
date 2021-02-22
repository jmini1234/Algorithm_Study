#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
bool visit[200];
void bfs(int row, int col, vector<vector<int>>& v)
{
	queue<int> q;
	q.push(row);
	visit[col] = true;
	int r, next;
	while (!q.empty()) {
		r = q.front();
		q.pop();
		for (int i = 0; i<v[0].size(); i++) {
			next = i;
			if (r == next)
				continue;
			if (visit[next] == false && v[r][next] == 1) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i<computers.size(); i++) {
		for (int j = 0; j<computers[0].size(); j++) {
			if (visit[i] == false && computers[i][j] == 1) {
				answer++;
				bfs(i, j, computers);
			}
		}
	}
	return answer;
}