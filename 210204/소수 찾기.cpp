#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <set>
using namespace std;

bool visited[10];
vector<char> v;
set<int> s;
int answer=0;

bool isPrime(int num)
{
    if(num<2) // 0과 1은 소수에서 제외
        return false;
    for(int i=2; i<=sqrt(num); i++) // 2부터 주어진 수의 제곱근까지 포함하여 겁사
        if(num%i==0) // 나누어 떨어지면 소수가 아님
            return false;
    return true;
}

void dfs(string numbers, string str){
    if(str!=""){
        // 중복 체크를 막기 위해
        int num = stoi(str);
        if(s.find(num)==s.end()){
            s.insert(num);
            if(isPrime(num))
                answer++;
        }
    }
    
    for(int i=0;i<numbers.size();i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(numbers,str+numbers[i]);
            visited[i]=false;
        }
    }
    
}

int solution(string numbers) {
    
    string str="";
    dfs(numbers,str);
    return answer;
}