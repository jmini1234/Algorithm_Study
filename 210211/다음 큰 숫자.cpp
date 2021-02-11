#include <string>
#include <vector>

using namespace std;
int one_cnt_n;

int change_binary(int n){
    int one_cnt=0;
    while(n!=0){
        if(n%2==1)
            one_cnt++;
        n/=2;
    }
    return one_cnt;
}

int solution(int n) {
    int answer = 0;
    // n의 1의 개수
    one_cnt_n = change_binary(n);
    
    for(int i=n+1;i<1000001;i++){
        // n보다 큰 수 중에서 1의 개수가 같으면
        if(change_binary(i)==one_cnt_n){
            answer=i;
            break;
        }
    }
    
    return answer;
}