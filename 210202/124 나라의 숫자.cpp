#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int r;
	
    while(n){
        r=n%3;
        n/=3;
        if(r==0){
            answer="4"+answer;
			//3으로 나누어질 때만 몫을 1감소
            n--;
        }
        else if(r==1){
            answer="1"+answer;           
        }
        else{
            answer="2"+answer; 
        }        
    }
    return answer;
}