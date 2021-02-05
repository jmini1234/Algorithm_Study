#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool cmp(string& a, string& b) {
	return a + b > b + a;
}
string solution(vector<int> numbers) {
	string answer = "";
	vector<string> str;
	for (const auto& item : numbers)
		str.push_back(to_string(item));
	sort(str.begin(), str.end(), cmp);
	if (str[0] == "0")
		return "0";
	for (const auto& number : str)
		answer += number;
	return answer;
}