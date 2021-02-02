#include <iostream>
#include <string>
#include <stack>
using namespace std;
char table[] = { '1', '2', '4' };
string solution(int n) {
	string answer = "";
	while (n > 0) {
		n -= 1;
		answer.insert(0, 1, table[n % 3]);
		n /= 3;
	}
	return answer;
}