#include <iostream>
#include <vector>

using namespace std;

void vInsertForward(vector<int>& v, int num)
{
	for (int i = v.size() - 1; i > 0; --i)
		v[i] = v[i - 1];

	v[0] = num;
}

int vFind(vector<int> v, int num)
{
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == num)
			return i;

	return -1;
}

void vMoveForward(vector<int>& v, int idx)
{
	int temp = v[idx];

	for (int i = idx; i > 0; --i)
		v[i] = v[i - 1];

	v[0] = temp;
}

int main()
{
	int S, N, input;
	scanf_s("%d %d", &S, &N);

	vector<int> v(S);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d", &input);

		int findIdx = vFind(v, input);

		if (findIdx == -1) // ���Ϳ��� input�� ���ٸ�?
			vInsertForward(v, input); // forward�� input ����
		else if (findIdx != 0) // ���Ϳ��� input�� ã������, ù��° ��ġ�� �ƴ϶��?
			vMoveForward(v, findIdx); // ������ ����
	}

	for (int i = 0; i < S; ++i)
		printf("%d ", v[i]);
}