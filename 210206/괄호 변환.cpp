#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string answer = "";

// 올바른 문자열 확인 함수
bool IsRight(string str){
    stack<char> st;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(ch=='(')
            st.push(ch);
        else{
            if(st.empty()||st.top()!='('){
                return false;
            }
            st.pop();
        }
    }
    // 원래 추가
    if(!st.empty())
        return false;
    return true;
}
// 균형잡힌 문자열 확인 함수
bool IsBalanced(string str){
    int left=0;
    int right=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='(')
            left++;
        else
            right++;
    }
    if(left==right)
        return true;
    return false;
}

// p에 대해서 재귀적으로 계산할 함수
string cal(string p){
    // 1. 빈 문자열인 경우 반환
    if(p.size()==0)
        return "";
    // 2.균형잡힌 괄호 문자열 u, v로 분리
    string u,v;
    for(int size=2;size<=p.size();size+=2){
        u = p.substr(0,size);
        v = p.substr(size,p.size()-size);
        if(IsBalanced(u) && IsBalanced(v))
            break;
    }
    // 3. u가 올바른 괄호이면 v에 대해 다시 진행
    // u에 이어 붙힌 후 반환
    if(IsRight(u)){
        u = u+cal(v);
        return u;
    }
    // 4. 올바른 문자열이 아니라면
    else{
        // 4-1
        string total="(";
        // 4-2
        total+=cal(v);
        // 4-3
        total+=')';
        // 4-4
        u.erase(u.begin());
        u.erase(u.end()-1);
        for(int i=0;i<u.size();i++){
            if(u[i]=='(')
                total+=')';
            else
                total+='(';
        }
        return total;
    }
}

string solution(string p) {
    // 올바른 문자열이라면 return
    if(IsRight(p))
        return p;
    // 그렇지 않다면 계산
    answer = cal(p);
    return answer;
}