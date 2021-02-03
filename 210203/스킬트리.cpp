#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
using namespace std;
// 37분
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    set<char> s;
    // skill 에 있는 문자만 확인하기 위해 hash set에 저장
    for(int i=0;i<skill.size();i++)
        s.insert(skill[i]);
    // 각 후보군 마다 skill에 있는 문자들만 비교하기 위해 새로운 문자열 만듦
    for(int i=0;i<skill_trees.size();i++){
        string str = skill_trees[i];
        string new_str="";
        for(int i=0;i<str.size();i++){
            if(s.find(str[i])!=s.end())
                new_str+=str[i];
        }
        bool flag=true;
        // new_str의 크기가 더 크면 이미 앞에서 통과가 된 경우에도 
        // 틀린 값이 나올 수 있기 때문에 더 작은 길이로 비교한다.
        int size = min(new_str.size(),skill.size());
        for(int i=0;i<size;i++){
            if(new_str[i]!=skill[i]){
                flag=false;
                break;
            }
        }
        if(flag)
            answer++;
    }
    
    return answer;
}