#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAX_SIZE 500
int dp[MAX_SIZE][MAX_SIZE];
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	dp[0][0] = triangle[0][0];
	for (int i = 0; i < triangle.size() - 1; i++) {
		dp[i + 1][0] = dp[i][0] + triangle[i + 1][0];
		dp[i + 1][triangle[i + 1].size() - 1] =
			dp[i][triangle[i].size() - 1] + triangle[i + 1][triangle[i + 1].size() - 1];
		for (int j = 1; j < triangle[i + 1].size() - 1; j++) {
			dp[i + 1][j] = max(dp[i][j - 1] + triangle[i + 1][j],
				dp[i][j] + triangle[i + 1][j]);
		}
	}

	int height = triangle.size();
	for (int i = 0; i<triangle[height - 1].size(); i++)
		answer = max(answer, dp[height - 1][i]);
	return answer;
}