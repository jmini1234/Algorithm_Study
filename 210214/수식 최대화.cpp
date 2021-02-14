#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <deque>
#include <limits.h>

using namespace std;
// 연산자 우선순위 계산 방법

unordered_set<char> myset;
deque<long long> num;
deque<char> op;

long long cal(long long n1, long long n2, char op){
    if(op=='-')
        return n1-n2;
    if(op=='+')
        return n1+n2;
    if(op=='*')
        return n1*n2;
}

long long solution(string expression) {
    long long answer = LLONG_MIN;
    string tmp;
    // 표현식에 있는 부호와 숫자 따로 저장
    for(int i=0;i<expression.size();i++){
        char ch = expression[i];
        if(ch>='0' && ch<='9')
            tmp+=ch;
        else{
            num.push_back(stoi(tmp));
            op.push_back(ch);
            tmp.clear();
            if(myset.find(ch)==myset.end())
                myset.insert(ch);
        }
    }
    num.push_back(stoi(tmp));
    // 모든 부호의 순열을 만들기 위해
    vector<char> oper(myset.begin(),myset.end());
    sort(oper.begin(),oper.end());
    
    do{
        deque<long long> tmp_num = num;
        deque<char> tmp_op = op;
        for(auto &k:oper){
            // k oper에 대해서 계산 진행
            for(int i=0;i<tmp_op.size();i++){
                // 이번에 계산해야할 k 부호가 나오면 두 수 뽑아서 계산 후 다시 넣기
                if(tmp_op[i]==k){
                    long long n1 = tmp_num[i];
                    long long n2 = tmp_num[i+1];
                    long long new_n = cal(n1,n2,k);
                    // i번째 인덱스 삭제 
                    tmp_num.erase(tmp_num.begin()+i);
                    tmp_num.erase(tmp_num.begin()+i);
                    tmp_op.erase(tmp_op.begin()+i);
                    // 새로운 값 넣기
                    tmp_num.insert(tmp_num.begin()+i,new_n);
                    i--;
                }
            }
        }
        // 모든 계산이 끝나면 숫자 하나만 남는다.
        answer = max(answer,abs(tmp_num[0]));
    }while(next_permutation(oper.begin(),oper.end()));
    return answer;
}