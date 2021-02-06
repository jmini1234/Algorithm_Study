#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i=1;i<=s.size()/2;i++){
        string total;
        // i개 단위로 잘라 압축 시도
        unordered_map<string,int> m;

        int cnt=1;
        string prevstr = s.substr(0,i);
        for(int idx=i;idx<s.size();idx+=i){
            string substr;
            // i개 단위로 자를 수 없으면 마지막까지 자른다.
            if(idx+i>=s.size())
                substr = s.substr(idx,s.size()-idx);
            else
                substr = s.substr(idx,i);
            
            // 현재 문자열과 이전 문자열 비교해서 같으면 cnt 증가
            if(prevstr == substr){
                cnt++;
            }
            else{
                // cnt가 1이면 그냥 붙이기
                if(cnt==1)
                    total+=prevstr;
                // 그렇지 않으면 cnt까지 붙이기
                else
                    total+=to_string(cnt)+prevstr;
                // 갱신
                prevstr = substr;
                cnt=1;
            }
        }
        // 마지막 남은 수 처리
        if(cnt==1)
            total+=prevstr;
        else
            total+=to_string(cnt)+prevstr;
        
        if(total.size()<answer)
            answer = total.size();
    }
    
    return answer;
}