#include <iostream>
#include <vector>
using namespace std;

int N, M, minRes = INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> pizza;

int select[12];

void DFS(int l, int s)
{
	// ������ M���� �� �̾Ҵٸ�?
	if (l == M)
	{
		// ���� �Ÿ�
		int cityDistance = 0;

		// ��� ���� ���
		for (int i = 0; i < home.size(); ++i)
		{
			int pizzaDistance = INT_MAX;

			for (int j = 0; j < M; ++j)
			{
				// ���������κ��� �Ÿ��� ���ϱ�
				int dist = abs(home[i].first - pizza[select[j]].first) + abs(home[i].second - pizza[select[j]].second);

				// �������� ���� �ּ� �Ÿ��� ����
				pizzaDistance = min(pizzaDistance, dist);
			}

			// ���� �Ÿ� ���ϱ�
			cityDistance += pizzaDistance;
		}

		// ���� �ּ� �Ÿ� ���ϱ�
		minRes = min(minRes, cityDistance);
	}
	else
	{
		// pizza �߿��� M���� �̱� (DFS�� M���� �̱�)
		for (int i = s; i < pizza.size(); ++i)
		{
			select[l] = i;
			DFS(l + 1, i + 1);
		}
	}
}

int main()
{
	scanf_s("%d %d", &N, &M);

	int input;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf_s("%d", &input);

			if (input == 1)
				home.push_back({ i, j });
			else if (input == 2)
				pizza.push_back({ i, j });
		}
	}

	DFS(0, 0);

	printf("%d", minRes);
}