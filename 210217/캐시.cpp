#include <string>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;
deque<string> q;
set<string> s;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if(cacheSize==0)
        return cities.size()*5;
    
    for(auto &tmp:cities){
        string k;
        // tolower 함수는 char
        for(int i=0;i<tmp.size();i++){
            k+=tolower(tmp[i]);
        }
        
        // cache에 없으면
        if(s.find(k)==s.end()){
            answer+=5;
            // queue가 꽉 찼으면 삭제 후 값 push
            if(q.size()>=cacheSize){
                string remove_cache = q.front();
                q.pop_front();
                s.erase(remove_cache);
            }
            q.push_back(k);
            s.insert(k);
        }
        else{
            answer+=1;
            // LRU 알고리즘에 의해 사용된 값의 queue의 위치를 update해야한다.
            for(int i=0;i<q.size();i++){
                if(q[i]==k){
                    q.erase(q.begin()+i);
                    break;
                }
            }
            q.push_back(k);
        }
    }
    
    return answer;
}