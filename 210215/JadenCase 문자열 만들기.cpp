#include <string>
#include <vector>

using namespace std;
string answer = "";

void addString(string tmp){
    answer+=toupper(tmp[0]);
    for(int i=1;i<tmp.size();i++)
        answer+=tolower(tmp[i]);
    return;
}

string solution(string s) {
    string tmp="";
    for(int i=0;i<s.size();i++){
        tmp+=s[i];
        // 빈칸 나오면 변환
        if(s[i]==' '){
            addString(tmp);
            tmp="";
        }
    }
    // 마지막 단어도 변환
    if(tmp!="")
        addString(tmp);
    
    return answer;
}