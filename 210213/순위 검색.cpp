#include <bits/stdc++.h>

using namespace std;
unordered_map<string, vector<int>> m;

struct INFO{
    string lang;
    string dept;
    string year;
    string food;
    int score;
};

vector<string> tmpInfo;
bool visited[5]={false,};

// 주어진 info가 적용될 수 있는 모든 query를 만든다.
// - 1개, 2개, 3개, 4개까지 적용 (using dfs)
void dfs(int idx, int cnt, int total){
    if(cnt==total){
        string str;
        for(int i=0;i<4;i++){
            if(!visited[i])
                str+=tmpInfo[i];
            else
                str+='-';
        }
        m[str].push_back(stoi(tmpInfo[4]));
        return;
    }
    for(int i = idx;i<4;i++){
        if(!visited[i]){
            visited[i]=true;
            dfs(i+1, cnt+1, total);
            visited[i]=false;
        }
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    // info 값 나누어서 저장
    for(int i=0;i<info.size();i++){
        tmpInfo.clear();
        string tmp;
        for(int j=0;j<info[i].size();j++){
            if(info[i][j]==' '){
                tmpInfo.push_back(tmp);
                tmp.clear();
                continue;
            }
            tmp+=info[i][j];
        }
        tmpInfo.push_back(tmp);
        // 현재 info로 가능한 query 구해서 map에 저장
        for(int j=0;j<=4;j++){
            memset(visited,false,sizeof(visited));
            dfs(0,0,j);
        }
    }
    
    // map의 두번째 인자인 vector를 정렬하는 방법
    for(auto &k:m){
        sort(k.second.begin(),k.second.end());
    }

    // query 값 뽑아내서 저장
    for(int i=0;i<query.size();i++){
        string tmp;
        tmpInfo.clear();
        for(int j=0;j<query[i].size();j++){
            if(query[i][j]==' '){
                tmpInfo.push_back(tmp);
                // and 처리하기 위해 4칸 뒤로
                j+=4;
                tmp.clear();
                continue;
            }
            tmp+=query[i][j];
        }
        tmp.clear();
        // 점수는 따로 계산
        for(int j=query[i].size()-1;j>0;j--){
            if(query[i][j]==' '){
                tmpInfo.push_back(tmp);
                break;
            }
            tmp = query[i][j] + tmp;
        }
        int score = stoi(tmp);
        string cmd = tmpInfo[0]+tmpInfo[1]+tmpInfo[2]+tmpInfo[3];
        // 이분 탐색을 사용해서 정렬되어 있는 점수 중 
        // score보다 같거나 큰 가장 작은 iterator 반환
        auto p = lower_bound(m[cmd].begin(),m[cmd].end(),score);
        answer.push_back(m[cmd].end()-p);
    }
    return answer;
}