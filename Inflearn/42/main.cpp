#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	scanf_s("%d %d", &N, &M);

	vector<int> arr(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	/*
	int idx = N / 2;
	while (true)
	{
		// ���� idx�� ���Ұ��� ã���� �ϴ� ������ ũ��?
		if (arr[idx] > M)
			idx = idx / 2;
		// ���� idx�� ���Ұ��� ã���� �ϴ� ������ ������?
		else if (arr[idx] < M)
			idx = (idx + N) / 2;
		else
		{
			printf("%d", idx + 1);
			break;
		}
	}
	*/

	// lt, mid, rt�� ����Ͽ� ����

	int lt = 0, rt = N - 1, mid;

	while (true)
	{
		mid = (lt + rt) / 2;

		if (arr[mid] == M) // ���� ã�Ҵٸ�?
		{
			printf("%d", mid + 1);
			break;
		}
		else if (arr[mid] > M) // ���� ���� ã���� �ϴ� ������ ũ��? -> mid�� ����
		{
			rt = mid - 1;
		}
		else // ���� ���� ã���� �ϴ� ������ ������? -> mid�� ����
		{
			lt = mid + 1;
		}
	}
}