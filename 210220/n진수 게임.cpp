#include <bits/stdc++.h>

using namespace std;

// 각자리 수를 담기 위해
vector<char> v;
// 나머지에 대응되는 문자 값
char remain[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

// num을 n진법으로 바꿔서 string 값 반환
string makeNum(int num, int n){
    string tmp;
    if(num==0)
        tmp+='0';
    while(num!=0){
        tmp = remain[num%n]+tmp;
        num/=n;
    }
    return tmp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int i=0;
     while(1){
         // i를 n진수로 바꾼 값
        string tmp = makeNum(i,n);
         // 바꾼 문자열을 문자로 쪼개서 v에 저장
        for(int j=0;j<tmp.size();j++){
            v.push_back(tmp[j]);
        }
        // 튜브는 m명 중 t개를 p번째에 말해야하니까 v의 개수가 t*m*p보다는 커야한다.
        if(v.size()>=t*m*p)
            break;
        i++;
    }
    
    // 저장된 문자열에서
    for(int i=0;i<v.size();i++){
        // 인덱스가 현재 튜브의 순서가 맞으면(인덱스 처리 위해 1빼기)
        if(i%m==p-1)
            answer.push_back(v[i]);
        if(answer.size()==t)
            break;
    }
    return answer;
}