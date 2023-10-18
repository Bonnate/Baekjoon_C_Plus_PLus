#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct lecture {
	int day;
	int cost;

	lecture(int cost, int day) : day(day), cost(cost) {}

	// ������ �����ε����� day�� �������� ������ �� �ֵ��� ����
	bool operator < (const lecture& ref) const
	{
		return day > ref.day;
	}
};

int main()
{
	int N;
	scanf_s("%d", &N);

	vector<lecture> l;
	priority_queue<int> pQ;

	int day, cost, maxDay = INT_MIN, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d %d", &cost, &day);
		l.push_back(lecture(cost, day));

		if (maxDay < day)
			maxDay = day;
	}

	// day�� �������� �������� ����
	// day�� ���ƾ� ���� �ʰԱ��� ����ų �� ����
	sort(l.begin(), l.end());

	int j = 0;
	// day�� ���� ������� ����
	for (int i = maxDay; i >= 1; --i)
	{
		// ���ĵ� l�� 0���� �˻�
		for (; j < N; ++j)
		{
			// ���� ���õ� day�� ���ٸ� ť�� ����
			if (l[j].day == i)
				pQ.push(l[j].cost);
			else
				break;
		}

		// ť�� ���� �ִٸ� pop�Ͽ� sum�� ���ϱ�
		if (!pQ.empty())
		{
			sum += pQ.top();
			pQ.pop();
		}
	}

	printf("%d", sum);
}