#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set <int> s;
string str = "";
bool check[7];

void find_all_numbers(int depth, int limit, string& numbers) {
	if (depth == limit) return;

	for (int i = 0; i < limit; i++) {
		if (!check[i]) {
			check[i] = true;
			str.push_back(numbers[i]);
			s.insert(stoi(str));
			find_all_numbers(depth + 1, limit, numbers);
			str.pop_back();
			check[i] = false;
		}
	}
}
int solution(string numbers) {
	int size = numbers.size();

	find_all_numbers(0, size, numbers);

	int answer = 0;

	for (auto& it : s) {
		if (it == 1 || it == 0) continue;

		int num = it / 2;
		bool isDivided = false;
		for (int i = 2; i <= num; i++) {
			if (it % i == 0) isDivided = true;
		}
		if (!isDivided) answer++;
	}

	return answer;
}