#include <iostream>

using namespace std;
int main()
{
	int N, totalCnt = 0;
	scanf_s("%d", &N);

	// i�� 2, ���ڸ��� ���� ���� ����
	// i�� i�ڸ��� ������ �����Ѱ�? �� �˻�
	// ������� i�� 2��, ���ڸ��� ������ �������� �˻�
	for (int i = 2; ; ++i)
	{
		// N���� �� ������ ��
		// i�� 2���, N - 1 - 2�� ���� 12�� ������
		int remain = N - (i * (i + 1) / 2);

		if (remain < 0)
			break;

		// remain�� i�� ������������?
		// ���������ٸ�, i�ڸ��� ���� ǥ���� ��������
		if (remain % i != 0)
			continue;

		int sum = 0;
		int quotient = remain / i; // remain�� i�� ���� ��
		++totalCnt;

		// quotient�� j�� ���� ����� ǥ��
		// ������� i�� 2�� ���¿��� remain�� 6�̶��
		// 7 + 8 = 15�� ǥ�� ����
		for (int j = 1; j < i; ++j)
		{
			printf("%d + ", quotient + j);
			sum += (quotient + j);
		}

		printf("%d = %d\n", quotient + i, sum + quotient + i);
	}

	printf("%d", totalCnt);
}