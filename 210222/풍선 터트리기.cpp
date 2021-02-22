#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
	int answer = 2, len = a.size();
	if (len <= 2)
		return len;
	int left = a[0], right = a[len - 1];
	for (int i = 1; i < len - 1; i++) {
		if (left > a[i]) {
			left = a[i];
			answer++;
		}
		if (right > a[len - i - 1]) {
			right = a[len - i - 1];
			answer++;
		}
	}
	if (left == right)
		answer--;
	return answer;
}