#include <iostream>

int arr[1001];

// ���� ����Ű�� n���� ��� ���տ� �����ִ��� ����
int Find(int n)
{
	// �ε��� ��ȣ�� n�� ���ٸ� �ڱ� �ڽ��� ��Ʈ ���
	if (arr[n] == n)
		return n;
	else
		// arr[n] != n�̶��, n�� ��� ���տ� �����ִ� �����̱⿡ ��Ʈ�� ã���� ��� ȣ��
		// arr[n]�� ��Ʈ ����� ���� �־� ������ �� �ֵ��� ����ȭ
		return arr[n] = Find(arr[n]);
}

// a�� ���� ������ b�� �������� ����
void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a != b)
		arr[a] = b;
}

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	for (int i = 1; i <= N; ++i)
		arr[i] = i;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		scanf_s("%d %d", &a, &b);

		// �Է°� ���ÿ� ����
		Union(a, b);
	}

	scanf_s("%d %d", &a, &b);

	// a �� b�� ������ Ȯ��
	a = Find(a);
	b = Find(b);

	if (a == b)
		printf("YES");
	else
		printf("NO");
}