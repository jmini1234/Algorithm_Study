#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define MAX_SIZE 100001
int dp[MAX_SIZE];
int fibo(int n)
{
	if (dp[n] != 0) return dp[n];
	dp[n] = (fibo(n - 1) % 1234567) + (fibo(n - 2) % 1234567);
	return dp[n] % 1234567;
}
int solution(int n) {
	int answer = 0;
	dp[0] = 0; dp[1] = 1; dp[2] = 1;
	answer = fibo(n);
	return answer;
}