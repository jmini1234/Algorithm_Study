#include <bits/stdc++.h>

using namespace std;

bool IsTrue(int idx1, int idx2, char op, int target){
    // gap을 구할 때 1을 빼야한다.
    int gap = abs(idx1-idx2)-1;
    if(op=='='){
        if(gap==target)
            return true;
    }
    else if(op=='>'){
        if(gap>target)
            return true;
    }
    else{
        if(gap<target)
            return true;
    }
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    // 모든 조건을 만족할 수 있는가
    // 일단 모두 나열 후에 조건 맞는지 확인 
    string order = "ACFJMNRT";
    do{
        // 현재 order에 대해서 
        int cnt=0;
        for(int i=0;i<data.size();i++){
            string condi = data[i];
            char n1 = condi[0];
            char n2 = condi[2];
            int idx1 = order.find(n1);
            int idx2 = order.find(n2);
            char oper = condi[3];
            int num = condi[4]-'0';
            if(IsTrue(idx1,idx2,oper,num))
                cnt++;
        }
        // 모든 조건이 일치하는지 확인하기
        if(cnt==n)
            answer++;
    }while(next_permutation(order.begin(),order.end()));
    
    return answer;
}