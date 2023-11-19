#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> truck, vector<int> w) {
	vector<int> answer;
	map<int, priority_queue<int>> m;

	for (int i = 0; i < truck.size(); ++i)
	{
		printf("%d %d\n", truck[i], i);
		m[truck[i]].push(-i);
	}

	for (int i = 0; i < w.size(); ++i)
	{
		int minIdx = 150001;
		int currentWeight = 0;

		for (pair<int, priority_queue<int>> p : m)
		{
			if (w[i] <= p.first)
			{
				if (minIdx > -p.second.top())
				{
					minIdx = -p.second.top(); // �ε��� ��ȣ
					currentWeight = p.first;

					printf("test: %d %d\n", currentWeight, minIdx);
				}
			}
		}

		printf("%d %d\n", minIdx, currentWeight);

		minIdx; // ���� ���԰� �ִ� �ε��� ��ȣ
		currentWeight; // �ε��� ��ȣ�� �ش��ϴ� Ʈ���� ���� �뷮

		answer.push_back(minIdx);

		m[-currentWeight].pop();
		m[-(currentWeight - w[i])].push(-minIdx);

		if (m[-currentWeight].empty())
			m.erase(-currentWeight);
	}

	return answer;
}

int main()
{
	solution({ 1, 4, 5, 2, 4 }, { 2, 4, 4, 3, 2 });
}