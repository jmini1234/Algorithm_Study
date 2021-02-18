#include <bits/stdc++.h>

using namespace std;
// 2분

unordered_map<string,int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i=1;i<=26;i++){
        string tmp;
        tmp+='A'+i-1;
        m.insert({tmp,i});
    }
    
    int idx=27;
    for(int i=0;i<msg.size();i++){
        string tmp;
        tmp+=msg[i];
        int nidx=i;
        // 가장 긴 값을 찾기 위해 찾았으면 길이 추가하면서 while
        while(m.find(tmp)!=m.end()){
            nidx++;
            tmp+=msg[nidx];
        }
        // 제일 긴 찾을 수 있는 문자열
        i=nidx-1;
        tmp.pop_back();
        answer.push_back(m[tmp]);
        // 새로 추가할 문자가 있으면 
        if(i!=msg.size()-1)
            m.insert({tmp+msg[i+1],idx++});
        else
            m.insert({tmp,idx++});

    }
    

    
    return answer;
}