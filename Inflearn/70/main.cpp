#include <iostream>
#include <queue>
using namespace std;

vector<int> map[20]; // ���� ����Ʈ
bool visited[20];

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	int f, t; // from, to
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &f, &t);
		map[f - 1].push_back(t - 1);
	}

	queue<int> visit;
	visit.push(0); // 0�� ������ ����
	visited[0] = true;
	int distance[20];

	distance[0] = 0;

	while (!visit.empty())
	{
		// ���� ��ġ�� ��������
		int currentNode = visit.front();
		visit.pop();

		for (int i = 0; i < map[currentNode].size(); ++i)
		{
			// �ش� ��带 �湮���� �ʾҴٸ�?
			if (!visited[map[currentNode][i]])
			{
				// �ش� ��带 �湮
				visited[map[currentNode][i]] = true;

				// �湮 �Ÿ��� ���� ����� ���� �Ÿ� + 1
				distance[map[currentNode][i]] = distance[currentNode] + 1;

				// ť�� ����
				visit.push(map[currentNode][i]);
			}
		}
	}

	for (int i = 0; i < N; ++i)
		printf("%d : %d\n", i + 1, distance[i]);
}