#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int len = prices.size();
	int dur = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			++dur;
			if (prices[i] > prices[j]) {
				break;
			}
		}
		answer.push_back(dur);
		dur = 0;
	}
	return answer;
}