#include <string>
#include <vector>

using namespace std;
// dp문제 : 가로의 길이가 1이 증가할 때 이전 값에 영향을 받음

int dp[60001];

int solution(int n) {
    int answer = 0;
    dp[1]=1;
    dp[2]=2;
    // 규칙 찾기 (가로가 i-1인 곳에서 세로로 붙이기 or 가로가 i-2인 곳에서 가로로 두개 붙이기), 이 두 경우는 서로 중복되지 않는다.
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;   
    }
    answer = dp[n];
    return answer;
}