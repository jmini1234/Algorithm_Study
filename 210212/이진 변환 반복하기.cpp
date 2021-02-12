#include <string>
#include <vector>
#include <iostream>

using namespace std;

string changed_two(int num){
    string ans;
    while(num!=0){
        ans+=to_string(num%2);
        num/=2;
    }
    return ans;
}

vector<int> solution(string s) {
    vector<int> answer;
    // 이진 변환 횟수 , 0 제거 횟수
    int remove_zero=0;
    int cnt=0;
    // 1이 될 때까지 반복
    while(s!="1"){
        cnt++;
        string new_str;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0')
                new_str+=s[i];   
            else
                remove_zero++;
        }
        s = changed_two(new_str.size());
    }
    answer.push_back(cnt);
    answer.push_back(remove_zero);
    
    return answer;
}