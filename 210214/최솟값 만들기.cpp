#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;
// 그리디
int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    // 각 배열의 최대와 최솟값을 곱한다.
    int size = A.size();
    for(int i=0;i<size;i++){
        answer+=(A[i]*B[size-1-i]);
    }
    
    return answer;
}