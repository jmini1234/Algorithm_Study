#include <iostream>
#include <vector>
using namespace std;
int dp[1001][1001]={0,};
int min_val;
int n,m;
int dx[3] = {0,-1,-1};
int dy[3] = {-1,-1,0};
vector<vector<int>> boards;

int cnt(int i,int j){
    min_val=1001;
    int res=0;
    for(int k=0;k<3;k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 && nx<n && ny>=0 &&ny<m && dp[nx][ny]>0){
            res++;
            min_val = min(min_val, dp[nx][ny]);
        }
    }
    return res;
}

int solution(vector<vector<int>> board)
{
    int answer=0;
    boards.assign(board.begin(),board.end());
    n = board.size();
    m = board[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
			if (board[i][j] == 0)
				continue;
            // 1인 경우 최소 길이가 1인 정사각형 만들 수 있음
			dp[i][j] = 1;
            // 세 방향에 길이가 1 이상인 정사각형이 모두 존재하는지 확인
            if(cnt(i,j)==3){
                // 그 최소 정사각형의 길이에 +1을 할 수 있음
                dp[i][j]=min_val+1;
            }
            answer = max(dp[i][j],answer);
        }
    }
    answer*=answer;
    return answer;
}