#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ��忡 �湮 �Ͽ����� �˻�
bool linked[101];

int main()
{
	vector<vector<pair<int, int>>> graph; // �׷����� ���� ���� (������, ���)
	priority_queue<pair<int, int>> q; // �켱���� ť
	int cnt = 0;

	int V, E, sum = 0;
	scanf_s("%d %d", &V, &E);

	graph = vector<vector<pair<int, int>>>(V + 1);

	int f, t, w;
	for (int i = 0; i < E; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		graph[f].push_back({ t, w });
		graph[t].push_back({ f, w });
	}

	q.push({ 0, 1 }); // ����ġ�� 0�� 1�� ���� �������� ����

	while (cnt != V)
	{
		// ���� ����ġ�� ���� ������ ��������
		pair<int, int> data = q.top();
		q.pop();

		int weight = -data.first; // -data.first�� ����ġ ���� ��������
		int to = data.second; // ������

		// �̹� �湮�ߴ� ����� ��Ƽ��
		if (linked[to])
			continue;

		// ó�� �湮�ϴ� ����� ����

		sum += weight;
		++cnt;
		linked[to] = true;

		// ���� ��ġ���� �� �� �ִ� ��� ���� ������ ����
		for (int i = 0; i < graph[to].size(); ++i)
			q.push({ -graph[to][i].second, graph[to][i].first });
	}

	printf("%d", sum);
}