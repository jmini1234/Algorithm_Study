#include bitsstdc++.h

using namespace std;
 구현 - O(N^2) 시간초과
 연속된 두 알파벳을 짝지어 제거하는 규칙 - 최고 상단의 값과 비교 - stack 사용 - O(N) 
stackchar st;

int solution(string s)
{
    int answer = 0;
    for(int i=0;is.size();i++){
        char ch = s[i];
        if(!st.empty() && st.top()==ch){
            st.pop();
        }
        else{
            st.push(ch);
        }
    }
    if(st.empty())
        answer=1;
    
    return answer;
}