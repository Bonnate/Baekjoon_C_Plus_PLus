#include <iostream>
#include <queue>
using namespace std;

// Union-Find���� ���� ������ ������ �迭
int arr[1001];

// Find
int Find(int n)
{
	if (n == arr[n]) return n;
	else return arr[n] = Find(arr[n]);
}

// Union
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		arr[a] = b;
}

int main()
{
	int N, M, f, t, w, res = 0;
	scanf_s("%d %d", &N, &M);

	// �켱���� ť�� ����Ͽ� ���� ȿ�������� ����
	priority_queue<pair<int, pair<int, int>>> q; // -����ġ, ���, ����
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d %d", &f, &t, &w);
		q.push({ -w, {f, t} });
	}

	// ���� ���� �ʱ�ȭ
	for (int i = 1; i <= N; ++i)
		arr[i] = i;

	// ��� ���� ������ ���
	while (!q.empty())
	{
		// ���� ����� ���� ���� ������ ��������
		pair<int, pair<int, int>> data = q.top();
		q.pop();

		// ���� ����
		int weight = -data.first;
		int from = data.second.first;
		int to = data.second.second;

		// ������ ���� ���� ��������
		int a = Find(from);
		int b = Find(to);

		// ���� �ٸ� �����̶��?
		if (a != b)
		{
			// ����ġ�� ���ϰ�, ����
			res += weight;
			Union(from, to);
		}
	}

	printf("%d", res);
}