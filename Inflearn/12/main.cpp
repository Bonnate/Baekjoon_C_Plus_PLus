#include <iostream>
#include <string>

int main()
{
	int N;
	scanf_s("%d", &N);

	int answer = 0;
	int digit = 10;

	int digitCount = std::to_string(N).length();

	// ������ �ڸ��� �� ������ ��Ģ��� ���ϱ�
	for (int i = 1; i < digitCount; ++i)
		answer += 9 * std::pow(10, i - 1) * i;

	// ������ �ڸ������� ���� ������ ���ϱ�
	int left = N - (int)std::pow(10, digitCount - 1) + 1;
	answer += digitCount * left;

	printf("%d", answer);
}