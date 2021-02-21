#include <bits/stdc++.h>

using namespace std;

// 시간 처리 중요 
vector<pair<double, double>>v;

int solution(vector<string> lines) {
    int answer = 0;
    
    for(int i=0;i<lines.size();i++){
        string h, m, s, ms;
        int ih, im, is, process;
        // 소숫점을 없애기 위해 ms를 1로 생각한다
        h = lines[i].substr(11, 2);
        m = lines[i].substr(14, 2);
        s = lines[i].substr(17, 2);
        ms = lines[i].substr(20, 3);
        // 크기 5까지 진행해도 stod하면 문자 사라진다
        process = stod(lines[i].substr(24, 5)) * 1000;
        
        ih = stoi(h) * 3600 * 1000;
        im = stoi(m) * 60 * 1000;
        is = stoi(s) * 1000 + stoi(ms);
        // 처리시간 때문에 1을 더해줘야함
        int start_total = ih+im+is-process+1;
        int end_total = ih+im+is;
        
        v.push_back({start_total,end_total});
    }
    
    for(int i=0;i<v.size();i++){
        // 각 트래픽 별 끝나는 시간 기준 1초 내에 시작 시간이 겹치는 것이 있는지 확인 ..
        int end_time = v[i].second+1000;
        int cnt=0;
        for(int j=i;j<v.size();j++){
            if(end_time>v[j].first)
                cnt++;
        }
        answer = max(answer,cnt);
    }
    return answer;
}