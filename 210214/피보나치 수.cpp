#include <string>
#include <vector>

using namespace std;
long long arr[100000];
// dp를 이용한 피보나치 수
int solution(int n) {
    int answer = 0;
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=(arr[i-1]+arr[i-2])%1234567;
    }
    answer = arr[n];
    return answer;
}