#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool prime[3001];
bool visited[51]={false,};
int answer = 0;

// 에라토스테네스의 체 사용해서 소수 배열
void Prime(){
    // 1000 이하의 자연수가 3개니까 최대 3000까지 가능
    for(int i=2;i<=3000;i++){
        if(prime[i]){
            for(int j=i+i;j<=3000;j+=i){
                prime[j]=false;
            }     
        }
    }
}
// nums 벡터에서 3개의 조합을 뽑는 모든 경우의 수 
void dfs(int idx, int cnt, vector<int> &nums, int total){
    if(cnt==3){
        if(prime[total])
            answer++;
        return;
    }
    
    for(int i=idx;i<nums.size();i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(i+1, cnt+1, nums, total+nums[i]);
            visited[i]=false;
        }
    }
}

int solution(vector<int> nums) {
    memset(prime,true,sizeof(prime));
    Prime();
    
    dfs(0,0,nums,0);
    
    return answer;
}