#include <iostream>
#include<vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	int len = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum = A[i] * B[i];
		answer += sum;
	}
	return answer;
}