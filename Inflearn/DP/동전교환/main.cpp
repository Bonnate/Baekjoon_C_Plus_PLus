#include<iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	vector<int> coin(n);
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	cin >> m;

	// ������ ū ������ �ʱ�ȭ (INT_MAX)�� �ϸ� �����÷ο찡 ����
	vector<int> dy(m + 1, 1000);

	dy[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int value = coin[i];

		for (int j = value; j <= m; j++)
		{
			// �Ž����� ���� ������ value �� ������ + 1
			dy[j] = min(dy[j], dy[j - value] + 1);
		}
	}

	cout << dy[m];
	return 0;
}