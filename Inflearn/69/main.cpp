#include <iostream>
#include <vector>
using namespace std;

int queue[100], front = -1, back = -1;
vector<int> map[10];
int ch[10];

int main()
{
	int f, t; // from, to

	for (int i = 0; i < 6; ++i)
	{
		scanf_s("%d %d", &f, &t);
		map[f - 1].push_back(t - 1);
	}

	for (int i = 0; i < 10; ++i)
		ch[i] = false;

	// 0��° ���� ����
	queue[++back] = 0;
	ch[0] = true;

	// front�� back�� �����Ҷ����� �ݺ�
	while (front < back)
	{
		// ���� ����� ���� ������ �� front ����
		f = queue[++front];
		printf("%d ", f + 1);

		// ���� ��忡�� �� �� �ִ� ��� ��带 �˻�
		for (int i = 0; i < map[f].size(); ++i)
			// �湮���� ���� �����?
			if (ch[map[f][i]] == false)
			{
				// �ش� ��� ��ȣ�� ť�� ���� �� back ����
				queue[++back] = map[f][i];
				ch[map[f][i]] = true;
			}
	}
}