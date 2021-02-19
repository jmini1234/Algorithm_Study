#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    
    bool flag=false;
    char prev = words[0].back();
    s.insert(words[0]);
    for(int i=1;i<words.size();i++){
        int idx = i%n+1;
        // 종료 조건: 끝말잇기 규칙을 위배하거나, 이미 나왔던 단어를 다시 말할 경우
        if(words[i].front()!=prev || s.find(words[i])!=s.end()){
            flag=true;
            answer.push_back(idx);
            answer.push_back(i/n+1);
            break;
        }
        else{
            prev = words[i].back();
            s.insert(words[i]);
        }
    }
    if(!flag){
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}