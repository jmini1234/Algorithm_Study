#include <vector>
#include <algorithm>
#include <functional>

using namespace std;
bool IsPossible(const vector<int>& v, int h)
{
    int cnt = 0;
    for(const auto& item : v)
        if(item >= h)
            cnt++;
    if(cnt >= h)
        return true;
    else
        return false;
}
int solution(vector<int> citations) {
	int answer = 0;
    sort(citations.begin(), citations.end());
    int left = 0, right = citations[citations.size() - 1];
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(IsPossible(citations, mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    answer = right;
	return answer;
}