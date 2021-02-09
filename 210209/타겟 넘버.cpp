#include <string>
#include <vector>
// 31분
using namespace std;
int multi[2] = {-1,1};
int answer = 0;
int num_size;

// dfs로 가능한 부호의 조합과 계산 값 구하기

void dfs(int idx, int cnt, int val, int &target, vector<int> &numbers){
    if(cnt==num_size-1){
        if(val==target+numbers[idx])
            answer++;
        if(val==target-numbers[idx])
            answer++;
        return;
    }
    // 숫자의 순서는 고정되어 있기 때문에 두 개의 부호에 대해서만 처리
    for(int i=idx;i<num_size;i++){
        for(int k=0;k<2;k++){
            dfs(i+1, cnt+1, val+numbers[i]*multi[k], target, numbers);
        }
    }
    return;
}

int solution(vector<int> numbers, int target) {
    num_size = numbers.size();
    dfs(0,0,0,target,numbers);
    return answer;
}