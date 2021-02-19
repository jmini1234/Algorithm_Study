#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string> s;
	int t, p;
	bool GameOver = false;
	for (int i = 0; i<words.size(); i++) {
		string& str = words[i];
		t = i;
		p = i % n;
		if (s.find(str) != s.end()) {
			GameOver = true;
			break;
		}
		else if (str.length() == 1) {
			GameOver = true;
			break;
		}
		else if (i != 0 && str[0] != words[i - 1][words[i - 1].length() - 1]) {
			GameOver = true;
			break;
		}
		s.insert(str);
	}
	t = t / n;
	if (!GameOver) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(p + 1);
		answer.push_back(t + 1);
	}
	return answer;
}