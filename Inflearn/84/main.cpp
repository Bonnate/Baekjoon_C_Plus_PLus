#include<stdio.h>

int N, T[16], P[16], res = 0;

void DFS(int L, int sum)
{
	// ��� ������ �Ϸ��Ͽ��ٸ�?
	if (L == N + 1)
		if (sum > res)
			res = sum;
		else
		{
			// ������� ���� + ���� ������ N + 1���� �۴ٸ�, ����� �õ�
			if (L + T[L] <= N + 1)
				DFS(L + T[L], sum + P[L]);

			// ����� ���� �ʴ� ��쵵 ��ͷ� ȣ��
			DFS(L + 1, sum);
		}
}

int main()
{
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf_s("%d %d", &T[i], &P[i]);

	DFS(1, 0);
	printf("%d\n", res);

	return 0;
}