#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
int arr[1001][1001];
int dx[3]={1,0,-1};
int dy[3]={0,1,-1};

vector<int> solution(int n) {
    vector<int> answer;
    // 채우는 끝 번호
    int endnum=(n*(n+1))/2;
    int x=0;
    int y=0;
    int num=1;
    int dir=0;
    while(1){
        arr[x][y]=num;
        // 끝번호까지 채웠으면 break
        if(num==endnum)
            break;
        // num과 방향으로 x,y 좌표 증가
        num++;        
        x+=dx[dir];
        y+=dy[dir];
        
        // 밖으로 나가거나 이미 채워진 곳이면 방향 바꾸기
        if(x<0 || x>=n || y<0 || y>=n || arr[x][y]!=0){
            x-=dx[dir];
            y-=dy[dir];
            dir = (dir+1)%3;
            x+=dx[dir];
            y+=dy[dir];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++)
            answer.push_back(arr[i][j]);
    }

    return answer;
}