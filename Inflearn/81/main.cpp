#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int from;
	int to;
	int weight;

	Edge(int from, int to, int weight) : from(from), to(to), weight(weight) {}

	bool operator < (const Edge& ref) const
	{
		return weight > ref.weight;
	}
};

int main()
{
	priority_queue<Edge> q;
	vector<Edge> edges; // ���� ������ ��� ����
	vector<int> dist; // ����ġ ����

	int N, M, f, t, w;
	scanf_s("%d %d", &N, &M);

	dist = vector<int>(N + 1, INT_MAX);

	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		edges.push_back({ f, t, w });
	}

	scanf_s("%d %d", &f, &t);
	dist[f] = 0;

	for (int i = 1; i < N; ++i) // ������ ������ 1������ �������� ���������� ����
		for (int j = 0; j < edges.size(); ++j) // ��� ������ �˻�
		{
			int from = edges[j].from; // ���� ��ġ�� ��
			int to = edges[j].to; // �������� �� ��
			int weight = edges[j].weight; // �������� ���� ���� ����ġ

			// ���� ���� ��ġ�� ����ġ�� INT_MAX�� �ƴϸ鼭(�ٸ� ������ ���� ���� ��ġ�� ��)
			// ��������� ����ġ + �������� ���� ���� ����ġ�� ����� ����ġ���� �۴ٸ�?
			if (dist[from] != INT_MAX && dist[from] + weight < dist[to])
				dist[to] = dist[from] + weight; // ����ġ ����
		}

	// ��� ���� ������ �ѹ��� �˻��Ͽ� ���� ����Ŭ�� �����ϴ��� Ȯ��
	for (int i = 0; i < edges.size(); ++i)
	{
		int from = edges[i].from;
		int to = edges[i].to;
		int weight = edges[i].weight;

		// ��������� ����ġ + �������� ���� ���� ����ġ�� ���� ��ġ�� ����� ����ġ���� �۴ٸ� ���� ����Ŭ�� ����
		if (dist[from] != INT_MAX && dist[from] + weight < dist[to])
		{
			printf("-1");
			exit(0);
		}
	}

	printf("%d", dist[t]);
}