#include <iostream>
using namespace std;

int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);

	int N, M, res = INT_MIN;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int t;
		int s;
		cin >> s >> t;

		// �� ������ �ѹ����� Ǭ�ٴ� ������ �ֱ⶧����
		// for���� M���� t���� ������ ���� ���� score�� ���� �ߺ� ������ ������ ����
		for (int j = M; j >= t; --j)
		{
			dp[j] = max(dp[j], dp[j - t] + s);
			res = max(res, dp[j]);
		}
	}

	cout << res;
}