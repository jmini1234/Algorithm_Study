#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
	for (int i = 0; i<arr1.size(); i++) {
		for (int j = 0; j<arr2[0].size(); j++) {
			int sum = 0;
			for (int w = 0; w < arr1[0].size(); w++) {
				sum += arr1[i][w] * arr2[w][j];
			}
			answer[i][j] = sum;
		}
	}
	return answer;
}