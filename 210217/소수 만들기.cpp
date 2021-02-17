#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#define PRIME 1
#define NOT_PRIME 2
int result = 0;
int dp[3000] = { 0, };
bool IsPrime(int sum)
{
	if (dp[sum] == PRIME)
		return true;
	else if (dp[sum] == NOT_PRIME)
		return false;
	else if (sum % 2 == 0) {
		dp[sum] = NOT_PRIME;
		return false;
	}

	for (int i = 3; i <= sqrt(sum); i += 2) {
		if (sum % i == 0) {
			dp[sum] = NOT_PRIME;
			return false;
		}
	}
	dp[sum] = PRIME;
	return true;
}
int solution(vector<int> nums) {
	int size = nums.size();
	for (int i = 0; i<size; i++) {
		for (int j = i + 1; j<size; j++) {
			for (int k = j + 1; k<size; k++) {
				int num = nums[i] + nums[j] + nums[k];
				if (IsPrime(num)) result++;
			}
		}
	}
	return result;
}