#include <vector>
#include <unordered_set>
using namespace std;
unordered_set<int> s;
int solution(vector<int> nums)
{
    int answer = 0;
    
    for(auto &k:nums){
        if(s.find(k)==s.end())
            s.insert(k);
    }
    // n/2보다 더 많은 종류를 가지고 있을 때 
    if(s.size()>=nums.size()/2)
        answer=nums.size()/2;
    else
        answer = s.size();
    
    return answer;
}