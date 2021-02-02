#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string s=new_id;
    
    for(int i=0;i<s.size();i++) {
        if(s[i]>='A'&&s[i]<='Z') s[i]|=32;
    }
 
    for(int i=0;i<s.size();i++) {      
        if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')||s[i]=='-'||s[i]=='_'||s[i]=='.')) {
            s.erase(i,1);
            i--;
        }
    }
     for(int i=1;i<s.size();i++) {      
        if(s[i-1]=='.'&&s[i]=='.') {
            s.erase(i,1);
            i--;
        }
    }
    if(s[0]=='.') s.erase(0,1);
    if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    
    if(s.size() == 0) s+='a';
    
    if(s.size() >= 16) s.erase(15,s.size()-15);
    if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    if(s.size() <= 2){
        int rt=3-s.size();
        for(int i=0;i<rt;i++){
            s+=s[s.size()-1];
        }
    }
        return s;
}
