#include <iostream>

int N, min = INT_MAX, max = INT_MIN;

int numbers[11];

// ������ ����� �� (1~9)
bool ch[10];
int res[10];
int operators[10];

int calc(int a, int b, int operatorId)
{
	switch (operatorId)
	{
	case 1:
		return a + b;
	case 2:
		return a - b;
	case 3:
		return a * b;
	case 4:
		return a / b;
	}
}

void DFS(int level)
{
	// ��� ������ R�� �����ߴٸ�?
	if (level == N - 1)
	{
		// ���� 1ȸ ���
		int result = calc(numbers[1], numbers[2], operators[res[1]]);

		// �������ʹ� ������ ������ ���
		for (int i = 2; i < N; ++i)
			result = calc(result, numbers[i + 1], operators[res[i]]);

		if (max < result)
			max = result;
		if (min > result)
			min = result;
	}
	else
	{
		for (int i = 1; i <= N - 1; ++i)
		{
			if (!ch[i])
			{
				// ��� ����� res[level + 1]�� ���
				res[level + 1] = i;

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
	scanf_s("%d", &N);

	for (int i = 1; i <= N; ++i)
	{
		scanf_s("%d", &numbers[i]);
	}

	int plus, minus, multiply, divide;
	scanf_s("%d %d %d %d", &plus, &minus, &multiply, &divide);

	int idx = 0;
	for (int i = 0; i < plus; ++i)
		operators[++idx] = 1;

	for (int i = 0; i < minus; ++i)
		operators[++idx] = 2;

	for (int i = 0; i < multiply; ++i)
		operators[++idx] = 3;

	for (int i = 0; i < divide; ++i)
		operators[++idx] = 4;

	// 0�� �ε����� ����
	DFS(0);

	printf("%d\n%d", max, min);
}