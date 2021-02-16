#include <string>
#include <vector>

using namespace std;
int num=1;
// 브루트 포스
// 다른 알고리즘 : 두 수의 최소공배수를 구하고, 그 최소공배수와 다른 수의 최소공배수를 계속해서 구한다.
int solution(vector<int> arr) {
    int answer = 0;
    long long total=1;
    for(auto &k:arr)
        total*=k;
    
    for(long long i=1;i<=total;i++){
        bool flag=true;
        for(auto &k:arr){
            if(i%k!=0){
                flag=false;
                break;
            }
        }
        if(flag)
            return i;
    }
}