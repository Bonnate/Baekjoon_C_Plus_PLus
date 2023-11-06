#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
	int answer = 0;
	int sum = 0;
	priority_queue<int> q;

	int i = 0;
	// sum�� n�� �ʰ��ϱ� ������ ť�� ����
	for (; i < enemy.size(); ++i)
		if (sum + enemy[i] > n)
			break;
		else
		{
			sum += enemy[i];
			q.push(enemy[i]);
		}

	// �������� ��� ����Ҷ����� �˻�
	for (; i < enemy.size() && k; ++i)
	{
		// ť�� ����
		q.push(enemy[i]);
		sum += enemy[i];

		// sum�� n�� �ʰ�(���簡 �����Ѱ��)
		if (sum > n)
		{
			// k(������)�� ����Ͽ� ���� ���簡 ���� �ʿ��� ��� ����
			sum -= q.top();
			q.pop();
			++answer;
			--k;
		}
	}

	// q�� �����ִ� �� ���ϱ�
	answer += q.size();

	// �������� ��� ���������, ������ ���带 �ִ��� �õ�
	for (; i < enemy.size(); ++i)
	{
		// ���� ���� �ʰ��Ǿ��ٸ� ������
		if (sum + enemy[i] > n)
			break;

		sum += enemy[i];
		++answer;
	}

	return answer;
}

int main()
{
	//solution(7, 3, { 4, 2, 4, 5, 3, 3, 1 });
	//solution(2, 4, { 3, 3, 3, 3 });
	//solution(5, 5, { 5, 5, 5, 5, 5, 1, 1, 1, 1, 1 });
	//solution(5, 5, { 1, 1, 1, 1, 1, 5, 5, 5, 5, 5 });
	//solution(1, 1, { 1, 2 });
	//solution(3, 2, { 1, 1, 1, 100, 100, 100 });
	//solution(199, 1, { 99, 99, 1, 101 });
	//solution(1, 2, { 2, 1, 2, 1 });
	//solution(5, 2, { 99, 1, 99 });
}