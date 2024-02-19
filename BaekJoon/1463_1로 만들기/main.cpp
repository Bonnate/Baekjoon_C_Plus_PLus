#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(1000001);

int main()
{
	int N;
	cin >> N;

	dp[1] = 0;

	// bottom-up
	for (int i = 2; i <= N; ++i)
	{
		// 1�� ���غ���
		dp[i] = dp[i - 1] + 1;

		// 3���� ������ �������ٸ�, ���� ����, 3���� ������ + 1�� �� �� ���� ���� ���
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);

		// 2�� ������ �������ٸ�, ���� ����, 2�� ������ + 1�� �� �� ���� ���� ���
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
	}

	cout << dp[N];
}