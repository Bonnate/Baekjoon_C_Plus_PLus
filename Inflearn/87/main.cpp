#include <iostream>
#include <queue>
using namespace std;

bool island[21][21];

// �� ������ ���� ȿ�������� ����ϱ� ���� ����
int dx[8]{ -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8]{ -1, -1, -1, 0, 0, 1, 1, 1 };

int main()
{
	int N;
	scanf_s("%d", &N);

	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf_s("%d", &island[i][j]);

	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// �� ���� �˻��Ͽ� ���̶�� ������ ������ ���
			if (island[i][j] == 1)
			{
				// ���� �����ϸ鼭 ������ 1 ���ϱ�
				++cnt;

				q.push({ i,j });
				island[i][j] = 0;

				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 8; ++k)
					{
						int xx = x + dx[k];
						int yy = y + dy[k];

						// ���� �Ÿ��� ������ ����ٸ� ������� �ʾƾ� ��
						if (xx < 0 || yy < 0 || xx > N || yy > N)
							continue;

						// �湮 ������ ��� �� ��ġ�� ����
						if (island[xx][yy] == 1)
						{
							island[xx][yy] = 0;
							q.push({ xx, yy });
						}
					}
				}
			}
		}
	}

	printf("%d", cnt);
}