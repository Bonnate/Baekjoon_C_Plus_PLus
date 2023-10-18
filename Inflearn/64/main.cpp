#include <iostream>
#include <vector>
using namespace std;

static int N, M, cnt = 0;
static vector <vector<bool>> arr;
static vector <bool> visited;

void DFS(int v)
{
	// �湮 TRUE
	visited[v] = true;

	// v(�湮��)�� N - 1(������ ���)�̶��?
	if (v == N - 1)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			// �� �湮�Ұ��� �ִٸ�?
			if (arr[v][i] == 1 && visited[i] == 0)
			{
				DFS(i); // �ش� ������ �� ã�ư��� (DFS)
				visited[i] = false; // �ش� �������� ����������, �ش� ���� �湮�� false�� ��ȯ
			}
		}
	}
}
int main()
{
	scanf_s("%d %d", &N, &M);

	arr = vector <vector<bool>>(N, vector<bool>(N, false));
	visited = vector<bool>(N, false);

	int f, t; // from, to
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &f, &t);

		arr[f - 1][t - 1] = true;
	}

	// 0��(�� ó��)���� �湮 ����
	DFS(0);

	printf("%d", cnt);
}