#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int size=0;
  
    for(int i=0;i<musicinfos.size();i++){
        // 재생 시간 구하기
        string start = musicinfos[i].substr(0,5);
        string end = musicinfos[i].substr(6,5);
        int hour = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
        int minute = stoi(end.substr(3,2))- stoi(start.substr(3,2));
        int total = minute+hour*60;
        // 음악의 이름 구하기
        string name;
        int cur_idx=12;
        int j;
        for(j=cur_idx;j<musicinfos[i].size();j++){
            if(musicinfos[i][j]==',')
                break;
            name+=musicinfos[i][j];
        }
        cur_idx = j;
        // 악보 구하기
        string info = musicinfos[i].substr(cur_idx+1, string::npos);
        int idx=0;
        string cur;
        // #에 대해서 처리하기 위해 
        // 문자 하나당 1초이기 때문에 문자의 수를 맞춰주기 위해 C# -> c, D# -> b ...
        while(cur.size()!=total){
            if(info[idx+1]=='#'){
                cur+=tolower(info[idx]);
                idx++;
            }
            else{
                cur+=info[idx];
            }
            idx = (idx+1)%info.size();
        }
        // m도 마찬가지로 문자열 변환
        string change_m;
        for(int i=0;i<m.size()-1;i++){
            if(m[i+1]=='#'){
                change_m+=tolower(m[i]);
                i++;
            }
            else
                change_m+=m[i];
        }
        if(m.back()!='#')
            change_m+=m.back();
        // 악보 반복 문자열에 찾는 문자열이 포함되고 긴 재생시간 일때 업데이트
        if(cur.find(change_m)!=string::npos && total>size){
            size = total;
            answer = name;
        }
    }
    
    return answer;
}