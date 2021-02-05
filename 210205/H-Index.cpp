#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 오름차순 정렬
    sort(citations.begin(),citations.end(),greater<int>());
    int lo = 0;
    int hi = 10001;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        // mid편 이상인 논문의 수, 나머지 논문의 수를 구한다.
        int upper_cnt=0;
        for(int i=0;i<citations.size();i++){
            if(citations[i]<mid)
                break;
            upper_cnt++;
        }
        int lower_cnt = citations.size()-upper_cnt;
        // mid편 이상인 논문의 수가 mid보다 작으면 mid를 줄여주어야한다.
        if(upper_cnt<mid){
            hi = mid-1;
        }
        // mid편 이하인 논문의 수가 mid보다 크면 mid를 감소시켜야한다. 
        if(lower_cnt>mid){
            lo = mid+1;
        }
        // 정답이면 갱신 후 더 큰 값을 시도해본다.
        else if (upper_cnt>=mid && lower_cnt<=mid){
            answer = max(answer,mid);
            lo = mid+1;
        }
    }
        
    return answer;
}