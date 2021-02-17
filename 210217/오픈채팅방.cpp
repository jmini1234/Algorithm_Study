#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
// 53분
map<string, string> m;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<pair<string, string>> v;
	for (int i = 0; i<record.size(); i++) {
		// 각각 명령어,uid, 닉네임 구하기
		string cmd;
		int idx = 0;
		int j;
		for (j = idx; j<record[i].size(); j++) {
			if (record[i][j] == ' ')
				break;
			cmd += record[i][j];
		}
		idx = j + 1;
		string Id;
		for (j = idx; j<record[i].size(); j++) {
			if (record[i][j] == ' ')
				break;
			Id += record[i][j];
		}
		idx = j + 1;
		string name;
		for (int j = idx; j<record[i].size(); j++) {
			if (record[i][j] == ' ')
				break;
			name += record[i][j];
		}

		// 들어왔을 때 map에서 이름 값 update
		if (cmd == "Enter") {
			m[Id] = name;
			v.push_back({ Id,cmd });
		}
		else if (cmd == "Leave") {
			v.push_back({ Id,cmd });
		}
		else {
			m[Id] = name;
		}
	}

	for (auto &k : v) {
		if (k.second == "Enter") {
			answer.push_back(m[k.first] + "님이 들어왔습니다.");
		}
		else if (k.second == "Leave") {
			answer.push_back(m[k.first] + "님이 나갔습니다.");
		}
	}

	return answer;
}