#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

// ���� ����
struct Edge1 {
	int from, to, weight;
};

int bellman_ford(int N, vector<vector<int>> road, int K) {
	vector<Edge1> edges;
	vector<int> dist(N + 1, INT_MAX);

	// �׷��� ���� �ʱ�ȭ (������ �׷����� ���� ��忡 ����)
	for (vector<int> r : road) {
		edges.push_back({ r[0], r[1], r[2] });
		edges.push_back({ r[1], r[0], r[2] });
	}

	// ���� ����� �Ÿ��� 0
	dist[1] = 0;

	// ����-���� �˰���
	// ��� ��忡 ���� ���� ª�� ��δ� ����� ������ �ϳ� ���� ������ ��(N-1)�� �̷�����⿡ N-1�� �ݺ�
	for (int i = 0; i < N - 1; ++i)
	{
		for (Edge1 edge : edges)
		{
			int from = edge.from;
			int to = edge.to;
			int weight = edge.weight;

			// ���� �ٸ� ������ ���� ����� ������ ������쿡�� ����
			if (dist[from] == INT_MAX)
			{
				printf("%d�� ���� ������ ����!\n", from);
				continue;
			}

			// ���� ��ġ�� ���(dist[from]) + ���� ��ġ������ ���(weight)�� ����� ���(dist[to])���� ������ ����
			if (dist[to] > dist[from] + weight)
			{
				printf("%d->%d�� %d���� %d�� ����!\n", from, to, dist[to], dist[from] + weight);
				dist[to] = dist[from] + weight;
			}
		}
		cout << endl;
	}

	// ���� ���ϱ�
	int answer = 0;
	for (int i = 1; i <= N; ++i)
		if (dist[i] <= K)
			++answer;

	return answer;
}

// ���� ����
struct Edge2 {
	int to, weight;
};

int dijkstra(int N, vector<vector<int>> road, int K) {
	vector<vector<Edge2>> graph(N + 1);
	vector<int> dist(N + 1, INT_MAX);

	// �׷��� ���� �ʱ�ȭ (�����)
	for (vector<int> r : road) {
		int from = r[0];
		int to = r[1];
		int weight = r[2];
		graph[from].push_back({ to, weight });
		graph[to].push_back({ from, weight });
	}

	// �켱���� ť�� �̿��� ���ͽ�Ʈ�� �˰���
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[1] = 0; // ���� ����� �Ÿ��� 0
	pq.push({ 0, 1 }); // {�Ÿ�, ���} ���� �켱���� ť�� ����

	while (!pq.empty()) {
		int current_distance = pq.top().first;
		int current_node = pq.top().second;
		pq.pop();

		printf("������ġ: %d, �������: %d\n", current_node, current_distance);

		// ���� ��忡�� �� �� �ִ� ��� ���鿡 ���� �ִ� �Ÿ� ����
		for (Edge2& e : graph[current_node])
		{
			int next_node = e.to;
			int weight = e.weight;

			printf("���� ���: %d, ���: %d\n", next_node, weight);

			if (dist[next_node] > current_distance + weight)
			{
				dist[next_node] = current_distance + weight;
				pq.push({ dist[next_node], next_node });

				printf("��� ����: %d, ���: %d\n", next_node, dist[next_node]);
			}
		}
	}

	// ���� ���ϱ�
	int answer = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (dist[i] <= K)
			++answer;

		cout << dist[i] << " ";
	}

	return answer;
}

int main()
{
	//bellman_ford(5, { {1, 2, 1}, { 2,3,3 }, { 5,2,2 }, { 1,4,2 }, { 5,3,1 }, { 5,4,2 } }, 3);
	//bellman_ford(6, { {1, 2, 1}, { 1,3,2 }, { 2,3,2 }, { 3,4,3 }, { 3,5,2 }, { 3,5,3 }, { 5,6,1 } }, 4);

	dijkstra(5, { {1, 2, 1}, { 2,3,3 }, { 5,2,2 }, { 1,4,2 }, { 5,3,1 }, { 5,4,2 } }, 3);
	//dijkstra(6, { {1, 2, 1}, { 1,3,2 }, { 2,3,2 }, { 3,4,3 }, { 3,5,2 }, { 3,5,3 }, { 5,6,1 } }, 4);
}