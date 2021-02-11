#include <bits/stdc++.h>
using namespace std;

int binary_counter(int num){
    return bitset<32>(num).count();
}

int solution(int n) {
    
    int answer = n+1;
    while(1){
        if (binary_counter(n) == binary_counter(answer)) break;
        answer++;    
    }
    return answer;
}