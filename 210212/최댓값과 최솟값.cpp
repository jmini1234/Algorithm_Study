#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int>v;

string solution(string s) {
    string answer = "";
    string tmp="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=' ')
            tmp+=s[i];
        // 공백이면 앞의 수 push 후 초기화
        else{
            v.push_back(stoi(tmp));
            tmp.clear();
        }
    }
    // 마지막 수 push
    v.push_back(stoi(tmp));
    
    sort(v.begin(),v.end());
    answer=to_string(v.front())+" "+to_string(v.back());
    return answer;
}