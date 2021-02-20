#include <bits/stdc++.h>

using namespace std;
// 37분
// 1. Head 기준(대소문자x)
// 2. number 기준(int로 바꿔서)
// 3. 들어온 순서


struct INFO{
    string head;
    int number;
    int idx;
};

vector<INFO> v;

// 문제에 맞춰 정렬 조건 
bool cmp(INFO p1, INFO p2){
    if(p1.head!=p2.head)
        return p1.head<p2.head;
    else{
        if(p1.number!=p2.number)
            return p1.number<p2.number;
        else
            return p1.idx<p2.idx;
    }
}

bool IsNum(char ch){
    if(ch>='0' && ch<='9')
        return true;
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    for(int j=0;j<files.size();j++){
        string str = files[j];
        string tmpH="";
        string tmpN="";
        int idx=0;
        for(int i=0;i<str.size();i++){
            // 숫자면 HEAD가 아니다
            if(IsNum(str[i])){
                idx=i;
                break;
            }
            tmpH+=tolower(str[i]);
        }
        for(int i=idx;i<str.size();i++){
            // 숫자가 아니면 NUMBER가 아니다
            if(!(IsNum(str[i]))){
                break;
            }
            tmpN+=str[i];
        }
        // HEAD와 NUMBER, 인덱스를 저장한다.
        v.push_back({tmpH,stoi(tmpN),j});        
    }
    
    // 정렬
    sort(v.begin(),v.end(),cmp);
    for(auto &k:v){
        answer.push_back(files[k.idx]);
    }
    
    return answer;
}