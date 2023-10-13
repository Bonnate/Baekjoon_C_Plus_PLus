#include <iostream>

void CheckGame(int a, int b);

int main()
{
	int arr[2][101];

	int N, A, B;
	scanf_s("%d", &N);

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < N; ++j)
			scanf_s("%d", &arr[i][j]);

	for (int i = 0; i < N; ++i)
		CheckGame(arr[0][i], arr[1][i]);
}

void CheckGame(int a, int b)
{
	// 1: ����
	// 2: ����
	// 3: ��

	// ���� ����
	if (a == b)
	{
		printf("D\n");
		return;
	}

	// �ºΰ� ���� ����
	switch (a) // A�� �� ��
	{
	case 1: // ����
		printf("%s\n", b == 3 ? "A" : "B");
		break;
	case 2: // ����
		printf("%s\n", b == 1 ? "A" : "B");
		break;
	case 3: // ��
		printf("%s\n", b == 2 ? "A" : "B");
		break;
	}
}