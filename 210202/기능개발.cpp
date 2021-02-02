#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> progresses, 
	vector<int> speeds) {
	vector<int> answer;
	int Max = 0, idx = 0, day = 0;
	map<int, int> result;
	for (auto& progress : progresses) {
		day = (100 - progress) % speeds[idx] 
			? (100 - progress) / speeds[idx] + 1 
			: (100 - progress) / speeds[idx];
		if (Max < day)
			result[day]++;
		else
			result[Max]++;
		Max = max(Max, day);
		day = 0;
		++idx;
	}
	for (const auto& it : result)
		answer.push_back(it.second);
	return answer;
}
