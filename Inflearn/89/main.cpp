#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];
int days[1001][1001];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	int M, N;
	queue<pair<int, int>> q;

	scanf_s("%d %d", &M, &N);

	// �Է��� �� ��, �ش� �丶�䰡 �;��ٸ�, ť�� ����
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			scanf_s("%d", &box[i][j]);
			if (box[i][j] == 1)
				q.push({ i, j });
		}

	// ť�� �������� �ݺ�
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			// �̵��� �� �ִ� ��ġ ���
			int xx = x + dx[i];
			int yy = y + dy[i];

			if (xx < 0 || yy < 0 || xx == N || yy == M)
				continue;

			// �ش� �丶�䰡 ���� �ʾҴٸ�?
			if (box[xx][yy] == 0)
			{
				box[xx][yy] = 1;

				// day�� 1�� ������Ű��
				days[xx][yy] = days[x][y] + 1;

				q.push({ xx , yy });
			}
		}
	}

	int res = -1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (box[i][j] == 0)
			{
				printf("-1");
				exit(0);
			}

			if (res < days[i][j])
				res = days[i][j];
		}
	}

	printf("%d", res);
}