#include <iostream>
#include <vector>
using namespace std;

int getMinIdx(int a, int b, int c)
{
	if (a > b)
		return b < c ? 2 : 3;
	else
		return a < c ? 1 : 3;
}

int main()
{
	int N;
	scanf_s("%d", &N);

	vector<int> arr{ 1 };

	int p2 = 0, p3 = 0, p5 = 0;
	int mul2, mul3, mul5;

	int minMulIdx;

	while (1)
	{
		mul2 = arr[p2] * 2;
		mul3 = arr[p3] * 3;
		mul5 = arr[p5] * 5;

		// ���� ������ ���� ��� ���ٸ�?
		if (mul2 == mul3 && mul3 == mul5)
		{
			arr.push_back(mul2);
			++p2, ++p3, ++p5;

			continue;
		}

		// ���� ���� ���� ������ �ε��� ��ȣ
		int minIdx = getMinIdx(mul2, mul3, mul5);

		switch (minIdx)
		{
		case 1: // �ε��� ��ȣ�� 1�� ��� ?
			arr.push_back(mul2);
			if (mul2 == mul3)
				++p2, ++p3;
			else if (mul2 == mul5)
				++p2, ++p5;
			else
				++p2;
			break;
		case 2: // �ε��� ��ȣ�� 2�� ��� ?
			arr.push_back(mul3);
			if (mul3 == mul2)
				++p3, ++p2;
			else if (mul3 == mul5)
				++p3, ++p5;
			else
				++p3;
			break;
		case 3: // �ε��� ��ȣ�� 3�� ��� ?
			arr.push_back(mul5);
			if (mul5 == mul2)
				++p5, ++p2;
			else if (mul5 == mul3)
				++p5, ++p3;
			else
				++p5;
			break;
		}

		// arr�� ����� �����Ѱ�� ?
		if (arr.size() >= N)
		{
			// ��� �� ����
			printf("%d", arr[N - 1]);
			return 0;
		}
	}
}