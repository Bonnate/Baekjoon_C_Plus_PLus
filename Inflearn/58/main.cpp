#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void D(int v)
{
	if (v > 7)
		return;
	else
	{
		// ���� ��ȸ
		//printf("%d", v);

		D(v * 2);

		// ���� ��ȸ
		//printf("%d", v);

		D(v * 2 + 1);

		// ���� ��ȸ
		printf("%d", v);
	}
}

int main()
{
	D(1);
}