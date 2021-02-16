#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
#define CONST_NUM 65536
map<string, int> m1, m2;
bool IsAlpha(const char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return true;
	return false;
}
int solution(string str1, string str2) {
	int answer = 0;
	string str;
	set<string> myset;
	int num;
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	for (int i = 1; i<str1.length(); i++) {
		if (IsAlpha(str1[i - 1]) && IsAlpha(str1[i])) {
			str = str1.substr(i - 1, 2);
			m1[str]++;
			myset.insert(str);
		}
	}
	for (int i = 1; i<str2.length(); i++) {
		if (IsAlpha(str2[i - 1]) && IsAlpha(str2[i])) {
			str = str2.substr(i - 1, 2);
			m2[str]++;
			myset.insert(str);
		}
	}
	if (myset.size() == 0)
		return CONST_NUM;
	int Intersection = 0, Union = 0;
	for (const auto& item : myset) {
		Intersection += min(m1[item], m2[item]);
		Union += max(m1[item], m2[item]);
	}
	double result = (double)Intersection / Union;
	answer = result * CONST_NUM;
	return answer;
}