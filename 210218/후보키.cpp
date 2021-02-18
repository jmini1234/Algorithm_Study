#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool used[10]={false,};
bool visited[10]={false,};
// 처음 틀린 부분 : find 함수로 만 중복되는 수 삭제함 
int n,m;
vector<int> res;
vector<vector<string>> relations;
vector<string> ans;

// 조합 구하기
void dfs(int idx, int cnt, int total){
    if(cnt==total){
        set<string>s;
        for(int i=0;i<relations.size();i++){
            string tmp;
            for(int j=0;j<res.size();j++){
                tmp+=relations[i][res[j]];
            }
            s.insert(tmp);
        }
        // 모두 후보키가 가능하다면 (column이 모두 set에 들어가면)
        if(s.size()==n){
            string tmp;
            // 조합의 인덱스를 더한 값을 넣는다.
            for(auto &k:res)
                tmp+=to_string(k);
            ans.push_back(tmp);
        }
        return;
    }
    for(int i=idx;i<m;i++){
        if(!used[i] && !visited[i]){
            visited[i]=true;
            res.push_back(i);
            dfs(i+1,cnt+1,total);
            res.pop_back();
            visited[i]=false;
        }
    }
}

int solution(vector<vector<string>> relation) {
    relations=relation;
    int answer = 0;
    n = relation.size();
    m = relation[0].size();
    for(int i=1;i<=m;i++){
        dfs(0,0,i);
    }
    
    vector<string> answerString;
    bool used[10]={false,};
    
    // 가능한 조합 중에서 최소성을 만족하는지 확인
    // ★ 주의 find 함수로 substring 만 확인하면 안됨 12가 있을때 321은 사라지지 않는다.
    // 모든 인덱스에 의해 들어있는지 확인하기
    for(auto &k:ans){
        string cur = k;
        bool flag=true;
        for(int i=0;i<answerString.size();i++){
            string cmp = answerString[i];
            int cnt=0;
            for(int l=0;l<cmp.size();l++){
                for(int m=0;m<cur.size();m++){
                    if(cur[m]==cmp[l])
                        cnt++;
                }
            }
            //cur문자열에서 cmp와 같은 문자열이 모두 발견되면
            if(cnt==cmp.size()){
                flag=false;
                break;
            }
        }
        if(flag)
            answerString.push_back(cur);
    }
    
    answer = answerString.size();
    return answer;
}