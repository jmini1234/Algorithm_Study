#include <bits/stdc++.h>

using namespace std;

bool asc(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    bool check[100001] = {false, }, open = false;
    vector<vector<int>> v;
    vector<int> num;
    string tmp = "";
    
    for(int i = 1; i < s.size() - 1; i++)
    {
        if(open == false && s[i] == '{')
            open = true;
        else if(open == true && (s[i] >= '0' && s[i] <= '9'))
        {
            tmp.push_back(s[i]);
        }
        else if(open == true && s[i] == ',')
        {
            int t = stoi(tmp);
            num.push_back(t);
            tmp = "";
        }
        else if(open == true && s[i] == '}')
        {
            int t = stoi(tmp);
            num.push_back(t);
            v.push_back(num);
            open = false;
            tmp = "";
            num.clear();
        }
    }
    
    sort(v.begin(), v.end(), asc);
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            if(check[v[i][j]] == false)
            {
                check[v[i][j]] = true;
                answer.push_back(v[i][j]);
            }
        }
    }
    return answer;
}
