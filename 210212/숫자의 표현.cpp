#include <string>
#include <vector>
#include <deque>
using namespace std;

deque<int>q;
// 연속합 
// 슬라이딩 윈도우 
int solution(int n) {
    int answer = 0;
    int total=0;
    int num=1;
    while(1){
        if(total<n){
            while(total<n){
                total+=num;
                q.push_back(num);
                num++;   
            }
        }
        else if(total>n){
            while(total>n){
                total-=q.front();
                q.pop_front();
                // 끝내는 조건 주의
                if(q.empty())
                    return answer;
            }
        }
        if(total==n){
            answer++;
            total-=q.front();
            q.pop_front();
        }        
    }    
}