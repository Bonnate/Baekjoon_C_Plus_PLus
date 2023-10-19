#include <iostream>

int N, R;
int arr[16];
bool ch[16];
int cnt = 0;
int res[16];

void DFS(int level)
{
	// ��� ������ R�� �����ߴٸ�?
	if (level == R)
	{
		++cnt;

		for (int i = 1; i <= R; ++i)
			printf("%d ", res[i]);

		printf("\n");
	}
	else
	{
		for (int i = 1; i <= N; ++i)
		{
			if (!ch[i])
			{
				// ��� ����� res[level + 1]�� ���
				res[level + 1] = arr[i];

				// ch[i]��°�� ���� ���� �����
				ch[i] = true;

				// ������ 1�� ����
				DFS(level + 1);

				// ch[i]��°�� ���� ���� ��� ����
				ch[i] = false;
			}
		}
	}
}

int main()
{
	scanf_s("%d %d", &N, &R);

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &arr[i]);
	}

	// 0�� �ε����� ����
	DFS(0);

	printf("%d", cnt);
}