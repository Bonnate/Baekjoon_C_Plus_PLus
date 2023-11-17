#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s;
	int n = prices.size();

	for (int i = 0; i < n; i++) {
		// ������ ������� �ʰ� ���ø����� ���� ���簪���� ũ�ٸ� -> ���� �������� �ǹ�
		while (!s.empty() && prices[s.top()] > prices[i]) {
			// ������ ���������Ƿ� i - ���ø����� ���� ����
			answer[s.top()] = i - s.top();
			s.pop();
		}
		// ���� �ε����� ���ÿ� �ֱ�
		s.push(i);
	}

	while (!s.empty()) {
		answer[s.top()] = n - s.top() - 1;
		s.pop();
	}

	return answer;
}

int main()
{
	solution({ 1, 2, 3, 2, 3 });
}