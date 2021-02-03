#include <vector>
#include <cstring>
using namespace std;
// 41분 

bool visited[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int M,N;
int tmp;
vector<vector<int>> arr;

bool IsRange(int x,int y){
    if(x>=0 && x<M && y>=0 && y<N)
        return true;
    return false;
}

void dfs(int x, int y, int num){
    visited[x][y]=true;
    tmp++;
    for(int k=0;k<4;k++){
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(IsRange(nx,ny) && !visited[nx][ny] && arr[nx][ny]==num){
            dfs(nx,ny,num);
        }
    }
    return;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    // 초기화 함수 내에서 진행
    tmp=0;
    M=m;
    N=n;
    arr=picture;
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0 && !visited[i][j]){
                tmp=0;
                number_of_area+=1;
                dfs(i,j,arr[i][j]);
                if(tmp>max_size_of_one_area)
                    max_size_of_one_area=tmp;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}