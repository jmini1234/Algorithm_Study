#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";
	istringstream ss(s);
	string num;
	vector<int> v;
	while (getline(ss, num, ' ')) {
		v.push_back(stoi(num));
	}
	sort(v.begin(), v.end());
	answer += to_string(v[0]);
	answer += ' ';
	answer += to_string(v[v.size() - 1]);
	return answer;
}