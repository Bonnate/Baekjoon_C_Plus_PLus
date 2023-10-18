#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int a;

	// �������� (�⺻��)
	//priority_queue<int> pQ;

	// �������� greater<int>�� ���
	priority_queue<int, vector<int>, greater<int>> pQ;

	while (true)
	{
		scanf_s("%d", &a);
		if (a == -1)
			break;

		if (a == 0)
			if (pQ.empty())
				printf("-1\n");
			else
			{
				printf("%d\n", pQ.top());
				pQ.pop();
			}
		else
		{
			pQ.push(a);
		}
	}
}