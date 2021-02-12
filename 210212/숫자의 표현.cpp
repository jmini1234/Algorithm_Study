#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(int n) {
	int answer = 1;
	deque<int> picked;
	int sum = 0;
	for (int i = 1; i <= n; ) {
		if (sum > n) {
			sum -= picked[0];
			picked.pop_front();
			continue;
		}
		else if (sum == n) {
			answer++;
		}
		sum += i;
		picked.push_back(i);
		i++;
	}
	return answer;
}