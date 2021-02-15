#include <bits/stdc++.h>
#include <iostream>

using namespace std;
char arr[31][31];
int answer = 0;
int N;
int M;
int cnt;
bool flag=false;
int dx[4][3] = {
    {0,-1,-1},
    {0,-1,-1},
    {0,1,1},
    {0,1,1}
};
int dy[4][3] = {
    {-1,-1,0},
    {1,0,1},
    {-1,-1,0},
    {1,0,1}
};

bool deleted[31][31]={false,};

bool IsRange(int x, int y){
    if(x>=0 && x<N && y>=0 && y<M)
        return true;
    return false;
}

void checkSame(int x, int y){
    // x와 y에 대해서 4방향 탐색
    char cur = arr[x][y];
    for(int i=0;i<4;i++){
        int count=0;
        for(int j=0;j<3;j++){
            int nx = x+dx[i][j];
            int ny = y+dy[i][j];
            // 범위 안에 있고 같은 경우에
            if(IsRange(nx,ny) && arr[nx][ny]==cur){
                count++;
            }
        }
        // 3개 모두 블록이 같고 범위 안에 있으면
        // 지운다고 표시
        if(count==3){
            // 하나라도 지워지는 값이 있음을 표시하는 flag 
            flag=true;
            for(int j=0;j<3;j++){
                int nx = x+dx[i][j];
                int ny = y+dy[i][j];
                deleted[nx][ny]=true;
            }
        }
    }
}

void select(){
    // 배열 초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            deleted[i][j]=false;
    }

    // 삭제된 값이 아닌 모든 값에 대해서 사라질 수 있는지 확인하기
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]=='0')
                continue;
            checkSame(i,j);
        }
    }
    
    // 사라져야하는 값 '0'으로 만들고 answer 업데이트
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(deleted[i][j]){
                arr[i][j]='0';
                answer++;
            }
        }
    } 
}

void down(){
    // x가 큰 값부터 내리기 
    for(int j=0;j<M;j++){
        for(int i=N-1;i>=0;i--){
            // 0이면 이동하지 않는다.
            if(arr[i][j]=='0')
                continue;
            int idx = i;
            int nidx = i;
            // 0이 아닌 값을 만날 때까지 인덱스 증가
            while(1){
                if(nidx+1>=N)
                    break;
                if(arr[nidx+1][j]!='0'){
                    break;
                }
                nidx++;
            }
            // 이동하지 않았으면
            if(idx==nidx)
                continue;
            // 이동
            arr[nidx][j]=arr[idx][j];
            arr[idx][j]='0';
        }
    }
}

int solution(int m, int n, vector<string> board) {
    N=m;
    M=n;
        
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            arr[i][j]=board[i][j];
        }
    }
    
    while(1){
        flag=false;
        // 더이상 터지는 값이 없으면 끝내기
        select();
        if(!flag)
            break;
        down();
    }
    
    return answer;
}