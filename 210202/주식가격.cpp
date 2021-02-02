#include <string>
#include <vector>
#include <stack>
using namespace std;
// 33분 stack으로 다시 풀기
// 시간복잡도 : stack O(n), 이중 for문 O(n^2)
// 일단 값이 감소하지 않은 방향으로 진행한다.
vector<int> solution(vector<int> prices) {
	// 각 인덱스별 주식 일수 저장
	vector<int> answer(prices.size());
	stack<int>st;
	for (int i = 0; i<prices.size(); i++) {
		//*새로 들어온 값에 의해 주식이 떨어져 answer이 결정되는 주식가격이 있는지 확인*
		while (!st.empty() && prices[st.top()]>prices[i]) {
			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);
	}
	// 새로 들어온 값에 의해 주식이 떨어지지 않음, 즉 끝까지 주식이 떨어지지 않은 인덱스들
	while (!st.empty()) {
		answer[st.top()] = prices.size() - st.top() - 1;
		st.pop();
	}
	return answer;
}