#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool trySetHorse(vector<int> arr, int c, int gap)
{
	int i = 0;
	int n = arr.size(); // �������� ����

	// ù��° ���� 0���� ��ġ�ϵ���
	--c;

	for (; i < n - 1; ++i)
	{
		for (int j = i; j < n - 1; ++j)
		{
			if (arr[j + 1] - arr[i] >= gap)
			{
				i = j + 1;
				--c;
			}

			if (c == 0)
				return true;
		}
	}

	return false;
}

int main()
{
	int N, C;
	scanf_s("%d %d", &N, &C);

	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);
	sort(arr.begin(), arr.end());

	int lt = 1, rt = arr[N - 1], mid;
	int res = 0;

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;

		bool isSuccess = trySetHorse(arr, C, mid);

		if (isSuccess) // �� ��ġ�� �����Ͽ��ٸ�?
		{
			res = mid;
			// lt�� �÷� �ִ� �Ÿ��� �ø���
			lt = mid + 1;
		}
		else // �� ��ġ�� �����Ͽ��ٸ�?
		{
			// rt�� �ٿ� �ִ� �Ÿ��� ���̱�
			rt = mid - 1;
		}
	}

	printf("%d", res);
}