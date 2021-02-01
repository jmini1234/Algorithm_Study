using namespace std;

//최대공약수 구함
int gcd(int w, int h){
    int min = w < h? w: h;
    for(int i=min;i>0;i--){
        if(w%i == 0 && h%i ==0) return i;
    }
}
//w+h-gcd(w,h) : 사용할 수 없는 정사각형의 수
long long solution(int w,int h) {
    long long answer = 1;
    return (long long)w*h- (w+h-gcd(w,h));
}