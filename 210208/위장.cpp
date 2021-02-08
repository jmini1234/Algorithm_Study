#include <string>
#include <vector>
#include <map> 

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i=0;i<clothes.size();i++){
        string ty = clothes[i][1];
        m[ty]++;
    }
    // 각 종류별로 조합 가능한 개수 (총 개수+1 (아예 착용하지 않을 때))
    for(auto &k :m){
        answer *= (k.second+1);
    }
    // 모두 착용하지 않는 경우 빼주기
    answer--;
    return answer;
}