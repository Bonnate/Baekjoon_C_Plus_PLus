#include <iostream>

int main()
{
	bool isJumper[101]{ false, };

	int N;
	scanf_s("%d", &N);

	int prev = 0, current = 0;
	scanf_s("%d", &prev);
	for (int i = 1; i < N; ++i)
	{
		scanf_s("%d", &current);

		// ���� ���ϱ�
		int diff = std::abs(current - prev);

		// ���̰� 100�� �Ѵ� ���� �Ұ���
		if (diff > 100)
		{
			printf("NO");
			return 0;
		}

		// diff�� �ش��ϴ� ���� ���
		isJumper[diff] = true;

		// prev �� ����
		prev = current;
	}

	for (int i = 1; i < N; ++i)
		if (!isJumper[i])
		{
			printf("NO");
			return 0;
		}
	printf("YES");
}