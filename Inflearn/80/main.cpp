#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int to;
	int weight;

	Edge(int to, int weight) : to(to), weight(weight) {}

	bool operator < (const Edge& ref) const
	{
		return weight > ref.weight;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<pair<int, int>> graph[21];
	vector<int> dist(21, INT_MAX);

	int N, M, f, t, w;
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		graph[f].push_back({ t, w });
	}

	// 1�� �������� ����
	q.push(Edge(1, 0));
	dist[1] = 0;

	while (!q.empty())
	{
		int current = q.top().to;
		int weight = q.top().weight;
		q.pop();

		// �ش� �������� �� ��, �̹� �� ���� ����� �Ÿ��� �ִٸ� ����
		if (weight > dist[current])
			continue;

		// current �������κ��� ����� �� �ִ� ��� �������� �湮�ϱ�
		for (int i = 0; i < graph[current].size(); ++i)
		{
			// ���� ����� ��ȣ�� ���� ����ġ ��������
			int next = graph[current][i].first;
			int nextWeight = weight + graph[current][i].second;

			// �ش� �������� ����� ����� ��뺸�� ���ٸ�?
			if (dist[next] > nextWeight)
			{
				// ��� ����
				dist[next] = nextWeight;

				// �ش� ��� �湮
				q.push(Edge(next, nextWeight));
			}
		}
	}

	for (int i = 2; i <= N; ++i)
	{
		printf("%d : ", i);

		if (dist[i] == INT_MAX)
			printf("impossible");
		else
			printf("%d", dist[i]);

		printf("\n");
	}
}