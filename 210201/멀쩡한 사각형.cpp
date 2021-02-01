#include<cmath>
#include<iostream>
using namespace std;
 
// 시간복잡도 O(H)
// 형변환 중요 
long long solution(int w,int h) {
	long long answer;
	long long sum = 0;
	for (int i = 1; i <= h; i++) {
        // 세로를 x축으로 봤을 때
        // 계산할 때 유의할 점: 곱하기부터 진행(w/h*i는 잘못된값이 나올 수 있다)
        // double 형 output을 만들기 위해 (int->double) 강제변환을 진행한다.
		double y1 = (double)w*i/h;
		double y2 = (double)w*(i - 1)/h;
		// 사용할 수 없는 사각형의 개수는 x좌표일 때 y값의 ceil에서 x-1좌표일 때 y값의 floor의 차이다. 
        sum += ceil(y1)-floor(y2);
	}
    // w*h는 long long이 될 수 있으므로 형변환 필수
	answer = (long long) w*h - sum;
	return answer;
}