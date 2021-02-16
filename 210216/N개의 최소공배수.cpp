#include <string>
#include <vector>

using namespace std;
//유클리드 호제법
int gcd(int a, int b)
{
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
//a * b = gcd(a, b) * lcm(a, b)
int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}
int solution(vector<int> arr) {
	int answer = arr[0];

	if (arr.size() == 1)
		return answer;

	for (int i = 1; i<arr.size(); i++)
		answer = lcm(answer, arr[i]);

	return answer;
}