#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 현재 정수를 이어 붙여서 큰 순서대로 정렬해야한다.
// 이어붙이는 계산은 문자열을 더한 수를 비교하면 된다 ★
bool cmp(string s1, string s2){
    return s1+s2 > s2+s1;
}

// 모든 경우의 수 -> 시간초과
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    for(auto &k:numbers){
        strNumbers.push_back(to_string(k));
    }
    sort(strNumbers.begin(),strNumbers.end(),cmp);
    
    // 정렬 후에도 가장 큰 수의 앞자리가 0이면 "0000"을 출력할 가능성이 있다.
    if(strNumbers[0]=="0")
        return "0";
    
    for(auto &k:strNumbers)
        answer+=k;
    
    return answer;
}