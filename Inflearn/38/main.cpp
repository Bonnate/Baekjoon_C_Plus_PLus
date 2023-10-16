#include <iostream>
#include <vector>

int main()
{
	int N;
	scanf_s("%d", &N);

	std::vector<int> iSeq(N), res(N);
	for (int i = 0; i < N; ++i)
		scanf_s("%d", &iSeq[i]);

	// �������� �׻� 0 (N���� ū ���� �տ� �� �� ����)
	res[N - 1] = N;

	// ���������� ��ĭ �� ���� ����
	for (int i = N - 2; i >= 0; --i)
	{
		// iSeq[i]��ŭ i + j��°�� �ִ� ���� �����ʿ� �ִ� �����κ��� ������
		for (int j = 0; j < iSeq[i]; ++j)
			res[i + j] = res[i + j + 1];

		res[i + iSeq[i]] = i + 1;
	}

	for (int i = 0; i < N; ++i)
		printf("%d ", res[i]);
}