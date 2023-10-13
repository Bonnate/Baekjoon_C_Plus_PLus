#include <iostream>

int main()
{
	int temperatures[100001];
	int temperatureSums[100001]{ 0, };
	int maxTempSum = INT_MIN;

	int N, K;
	scanf_s("%d %d", &N, &K);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &temperatures[i]);

	// ù��° �µ� �� ���ϱ�
	for (int i = 0; i < K; ++i)
		temperatureSums[0] += temperatures[i];
	maxTempSum = temperatureSums[0];

	// ������ �µ� ���� ���� ���� Ȱ���Ͽ� ���ϱ�
	for (int i = 1; i < N - K + 1; ++i)
	{
		temperatureSums[i] = temperatureSums[i - 1] - temperatures[i - 1] + temperatures[i + K - 1];
		maxTempSum = temperatureSums[i] > maxTempSum ? temperatureSums[i] : maxTempSum;
	}

	printf("%d", maxTempSum);
}