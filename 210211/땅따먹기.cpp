#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int n = land.size();
    vector<vector<int>> dp(n,vector<int>(4));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            if(i==0){
                dp[i][j]=land[i][j];
                continue;
            }
            // 같은 열 제외하고 최대값 찾기
            int max_val=0;
            for(int k=0;k<4;k++){
                if(k==j) 
                    continue;
                max_val = max(max_val, dp[i-1][k]);
            }
            // 최대값에 현재 값을 더하기
            dp[i][j]=land[i][j]+max_val;
        }
    }
    
    // n-1행 중 최대값 구하기
    for(int i=0;i<4;i++){
        answer = max(answer,dp[n-1][i]);
    }
    return answer;
}