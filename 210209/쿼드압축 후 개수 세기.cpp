#include <string>
#include <vector>
#include <iostream>


using namespace std;

int n, m;
int cnt[2] = {0,};

bool IsSame(vector<vector<int>>& arr, int x, int y, int size){
    int num = arr[x][y];
    for(int i=x;i<x+size;i++){
        for(int j=y; j<y+size;j++){
            if(arr[i][j]!=num)
                return false;
        }
    }
    return true;
}

void dfs(vector<vector<int>>& arr, int x, int y, int size){
    // 더이상 쪼갤 수 없을 때
    if(size == 1){
        cnt[arr[x][y]]++;
        return;
    }
    
    // 현재 크기로 압축 가능하면 return
    if(IsSame(arr, x,y,size)){
        cnt[arr[x][y]]++;
        return;
    }
    // 그렇지 않으면 4개의 부분으로 쪼개서 dfs 진행
    for(int i=x;i<x+size;i+=size/2){
        for(int j=y;j<y+size;j+=size/2){
            dfs(arr,i,j,size/2);
        }
    }
    
}

vector<int> solution(vector<vector<int>> arr) {
    n = arr.size();
    m = arr[0].size();
    vector<int> answer;
    dfs(arr, 0,0, arr.size());
    
    answer.push_back(cnt[0]);
    answer.push_back(cnt[1]);
    
    return answer;
}