#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 총 넓이에 대해서 가능한 노란 카펫의 넓이 모두 구하고 비교하기
    int sq_size = brown+yellow;
    for(int i=1;i<sq_size;i++){
        if(sq_size%i==0){
            int tmp_w = i;
            int tmp_h = sq_size/i;
            int tmp_yellow = (tmp_w-2) * (tmp_h-2);
            if(tmp_yellow == yellow){
                int w = max(tmp_w,tmp_h);
                int h = min(tmp_w,tmp_h);
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}