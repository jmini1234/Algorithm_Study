#include string
#include map
#include iostream
#include set

using namespace std;

 문자열의 방문 여부는 set으로 진행하기
 간단한 아이디어  모든 문자열 set에 넣고 total과 same 각각 max와 min으로 구하기
mapstring,intm1;
mapstring,intm2;
setstrings;

bool visited[3000]={false,};

bool IsAlpha(char ch){
    if((ch='A' && ch='Z')  (ch='a' && ch='z'))
        return true;
    return false;
}


int solution(string str1, string str2) {
    int answer = 0;
     for(int i=0;istr1.size()-1;i++){
        char ch1 = str1[i];
        char ch2 = str1[i+1];
        if(IsAlpha(ch1) && IsAlpha(ch2)){
            string new_str;
            new_str+=toupper(ch1);
            new_str+=toupper(ch2);
            m1[new_str]++;
        }
    }
    
     for(int i=0;istr2.size()-1;i++){
        char ch1 = str2[i];
        char ch2 = str2[i+1];
        if(IsAlpha(ch1) && IsAlpha(ch2)){
            string new_str;
            new_str+=toupper(ch1);
            new_str+=toupper(ch2);
            m2[new_str]++;
        }
    }
    int same_val=0;
    int total_val=0;
    
    for(auto &km1){
        string str = k.first;
        s.insert(str);
         m1에만 있는 경우
        if(m2.find(str)==m2.end()){
            total_val+=m1[str];
            continue;
        }
         m1,m2 공동으로 있는 경우
        same_val += min(m1[str],m2[str]);
        total_val += max(m1[str],m2[str]);
    }
    
     for(auto &km2){
        string str = k.first;
        string int_str;
        if(s.find(str)!=s.end())
            continue;
        if(m1.find(str)==m1.end()){
            total_val+=m2[str];
            continue;
        }
        same_val += min(m1[str],m2[str]);
        total_val += max(m1[str],m2[str]);
    }
        
    if(total_val==0)
        answer = 65536;
    else{
        double tmp = (double) same_val   (double) total_val;
        answer = tmp  65536;
    }
    
    return answer;
}