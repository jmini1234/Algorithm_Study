#include <iostream>

using namespace std;

// 2의 지수승이라는 특징 이용
int solution(int n, int a, int b)
{
    int answer = 0;
    // 몫으로 그룹 구하기 위해 1 빼주기
    a--;
    b--;
    while(1){
        // 서로 만날 때 끝남 경기 끝
        if(a==b)
            break;
        a = a/2;
        b = b/2;
        answer++;
    }
    return answer;
}