#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> st;

string solution(string number, int k) {
    string answer = "";
    int remove=0;
    int idx=-1;
    bool flag=true;
    for(int i=0;i<number.size();i++){
        int num = number[i]-'0';
        while(!st.empty() && st.top()<num){
            st.pop();
            remove++;
            // 이미 k개 만큼 제거했으면 뽑기 끝내기
            if(remove==k){
                idx=i;
                flag=false;
                break;
            }       
        }
        if(!flag)
            break;
        st.push(num);
    }
    
    // k개만큼 뽑았을 때 문자열이 더 길면 줄인다. 
    while(st.size()>number.size()-k){
        st.pop();
    }
    // 문자열이 더 짧으면 나머지 문자열을 더해준다.
    while(st.size()<number.size()-k && idx<number.size()){
        st.push(number[idx]-'0');
        idx++;
    }
    
    while(!st.empty()){
        answer = to_string(st.top()) + answer;
        st.pop();
    }
    
    return answer;
}