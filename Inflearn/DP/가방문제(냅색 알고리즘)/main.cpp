#include <iostream>
#include <algorithm>
using namespace std;

int w[30]; // weight
int v[30]; // value

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);

	int N, M, maxValue;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
		cin >> w[i] >> v[i];

	for (int i = 0; i < N; ++i)
	{
		int weight = w[i];
		int value = v[i];

		// ���� ���Ժ��� �����Ͽ� ������ ���������� �ݺ��Ͽ� �� ū ��ġ�� ����
		for (int j = weight; j <= M; ++j)
		{
			if (dp[j] < dp[j - weight] + value)
				dp[j] = dp[j - weight] + value;

			maxValue = max(maxValue, dp[j]);
		}
	}

	cout << maxValue;
}