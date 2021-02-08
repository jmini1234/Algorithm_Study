#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int i=0;i<phone_book.size()-1;i++){
        // 문자열 정렬하면 
        // 자신과 가장 비슷한 순서대로 정렬 된다.
        // 따라서 다음 문자열에 대해서만 비교해주면 된다. (다음 문자열이 접미사 아니면 그 다음 것들은 확인할 필요 없다.)
        if(phone_book[i]==phone_book[i+1].substr(0,phone_book[i].size()))
            return false;
    }
    
    return answer;
}