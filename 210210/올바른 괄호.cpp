#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;
vector<int> v[1000];
int max_size = 0;
unordered_set <int> myset;

vector<int> solution(string s) {
	vector<int> answer;
	string tmp;
	vector<int> tmpV;
	bool open = false;

	for (int i = 1; i<s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			tmp += s[i];
		// 괄호 열려있음 표시
		else if (s[i] == '{')
			open = true;
		// 쉼표이고 열려있을 때 값 넣기
		else if (s[i] == ',') {
			if (open) {
				tmpV.push_back(stoi(tmp));
				tmp.clear();
			}
		}
		// 닫는 괄호면 값 넣고 길이에 맞게 벡터에 넣기 
		else if (s[i] == '}') {
			open = false;
			tmpV.push_back(stoi(tmp));
			tmp.clear();

			int v_size = tmpV.size();
			max_size = max(v_size, max_size);
			v[v_size].assign(tmpV.begin(), tmpV.end());
			tmpV.clear();
		}
	}

	// 각 길이별로 set에 없는 값이 나오면 answer에 push 
	for (int i = 1; i <= max_size; i++) {
		for (int j = 0; j<v[i].size(); j++) {
			if (myset.find(v[i][j]) == myset.end()) {
				myset.insert(v[i][j]);
				answer.push_back(v[i][j]);
			}
		}
	}
	return answer;
}