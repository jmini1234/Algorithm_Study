#include string
#include vector
#include map
#include cstring
#include iostream
#include algorithm

 26분 55분
using namespace std;
mapstring,intm;
string order;

 순열을 통해 조합을 만들어낸다.
void dfs(int idx, string str,int num){
     num개(course 개)만큼 뽑으면
    if(str.size()==num){
         정렬해서 map에 개수를 count 한다. 
         정렬이유 = XW와 WX는 같은 조합이기 때문에 하나로 count하기 위해서
        sort(str.begin(),str.end());
        m[str]++;
        return;
    }
    for(int i=idx;iorder.size();i++){
        dfs(i+1,str+order[i],num);
    }
    return;
}

vectorstring solution(vectorstring orders, vectorint course) {
    vectorstring answer;
     모든 orders에 대해서 course개 만큼 조합을 만든다.
    for(int i=0;icourse.size();i++){
        int num = course[i];
        m.clear();
        for(int j=0;jorders.size();j++){
            order = orders[j];
            dfs(0,,num);
        }
         현재 course개만큼 뽑았을 때 가장 많이 등장한 문자열 answer에 저장
        int max_cnt=0;
        for(auto &km){
            if(k.secondmax_cnt && k.second=2)
                max_cnt= k.second;
        }
        for(auto &km){
            if(k.second==max_cnt)
                answer.push_back(k.first);
        }
    }
     정렬
    sort(answer.begin(),answer.end());
    return answer;
}