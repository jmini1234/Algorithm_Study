#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size();i++){
        int cnt = 0 ;
        for(int j=i+1;j<prices.size();j++){
			//가격이 떨어지지 않을 때까지 증가
            if(prices[j]>=prices[i]) cnt++;
            else{
				//가격이 떨어지면 빠져나옴
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    return answer;
}