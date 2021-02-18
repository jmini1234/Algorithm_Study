#include <bits/stdc++.h>

using namespace std;

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

/////////////////////////////////////////////////// 다른 풀이 //////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>

using namespace std;

vector<string> v;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i=1;i<=26;i++){
        string tmp;
        tmp+='A'+i-1;
        v.push_back(tmp);
    }
    
    for(int i=0;i<msg.size();i++){
        string tmp;
        tmp+=msg[i];
        int j;
        int idx=i;
        // 현재 문자열이 벡터에 존재하면
        // 더해보기
        while(find(v.begin(),v.end(),tmp)!=v.end()){
            j = find(v.begin(),v.end(),tmp)-v.begin();
            idx++;
            tmp+=msg[idx];
        }
        i=idx-1;
        // while을 사용해서 해당 문자열이 없으면 끝냄, 하지만 이 문자열을 다시 넣어주면 되기 때문에 tmp을 수정하지 않고 처리할 수 있다.
        answer.push_back(j+1);
        v.push_back(tmp);
    }
    
    return answer;
}
