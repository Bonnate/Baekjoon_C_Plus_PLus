#include <iostream>

using namespace std;

int main()
{
	int N;
	int age; // ���� �Է� �ӽ� ����

	int max = 2; // �ʱ� max�� �ּڰ�
	int min = 100; // �ʱ� min�� �ִ�

	scanf_s("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &age);

		if (age > max)
			max = age;
		else if (age < min)
			min = age;
	}

	printf("%d", max - min);
}