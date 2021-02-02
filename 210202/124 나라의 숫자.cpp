#include <string>
#include <vector>

using namespace std;
char get124[3] = {'1','2','4'};

// 기존 3진법 문제와 1씩 차이가 난다.
// 규칙 찾아서 적절히 바꾸기
string solution(int n) {
    string answer = "";
    while(n>0){
        n-=1;
        answer = get124[n%3]+answer;
        n/=3;
    }
    return answer;
}