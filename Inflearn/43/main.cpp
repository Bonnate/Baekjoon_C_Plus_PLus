#include <iostream>
#include <vector>

using namespace std;

int getCnt(vector<int> arr, int N, int size)
{
	int sum = 0;
	int cnt = 1; // ���� DVD�� ������ 1

	for (int i = 0; i < N; ++i)
	{
		if (sum + arr[i] > size) // DVD�� �뷮�� �ʰ��Ѱ��?
		{
			++cnt; // DVD�� �ϴ� ä���⶧���� 1 ����
			sum = arr[i]; // �ʰ��� ���� ���� sum�� �ֱ�
		}
		else // DVD�� �뷮�� ���� ��ä����
		{
			sum += arr[i]; // �뷮�� ���Ͽ� ä���
		}
	}

	return cnt;
}

int main()
{
	int N, M;
	int lt = 0, rt = 0, mid, res, max = INT_MIN;

	scanf_s("%d %d", &N, &M);
	vector<int> arr(N);

	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &arr[i]);
		rt += arr[i];
		max = max > arr[i] ? max : arr[i];
	}

	// lt�� ũ�Ⱑ rt�� ũ�⺸�� Ŀ�������� �ݺ�
	while (lt <= rt)
	{
		// DVD�� ũ��� (lt + rt) / 2
		mid = (lt + rt) / 2;

		// mid(���� DVD ������)�� ����������, DVD�� ����
		int cnt = getCnt(arr, N, mid);

		// DVD�� ũ��� max �̻��̾���ϸ�, DVD�� ������ M���� �۰ų� ���ٸ�?
		if (mid >= max && cnt <= M)
		{
			res = mid; // res�� ������ ����
			rt = mid - 1; // rt�� �ٿ� ������ �� ã�⸦ �ѹ� �� �õ�
		}
		// DVD�� ũ��(mid)�� max���� �۰ų�, cnt�� M(���� ��)���� ũ�ٸ�?
		else
		{
			lt = mid + 1; // lt�� �÷� DVD�� ũ�⸦ �÷� cnt�� M�� ���ߵ��� �õ�
		}
	}

	printf("%d", res);
}