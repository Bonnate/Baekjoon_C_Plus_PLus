#include <iostream>

int sel;
int used[10];
int ch[10];
char arr[10]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

/// <summary>
/// ������ �����ϰ� ������ ��� ����� ���� ����
/// </summary>
/// <param name="s"></param>
void DFS_ALL_Combinations(int s)
{
	if (s == sel)
	{
		for (int i = 0; i < sel; ++i)
			printf("%c ", arr[ch[i]]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i < sel; ++i)
			if (!used[i])
			{
				used[i] = true;
				ch[s] = i;
				DFS_ALL_Combinations(s + 1);
				used[i] = false;
			}
	}
}

/// <summary>
/// ������ �߿���Ͽ� �ߺ��� ���ŵ� ����
/// </summary>
/// <param name="l"></param>
/// <param name="s"></param>
void DFS_DISTINCT_Combinations(int l, int s)
{
	if (s == sel)
	{
		for (int i = 0; i < sel; ++i)
			printf("%c ", arr[ch[i]]);
		printf("\n");
	}
	else
	{
		// i�� ���� ���� �������� �����Ͽ� ������ ������ ������ �ݺ�
		for (int i = l; i < 10; ++i)
		{
			ch[s] = i; // s��° ������ ���� i��
			DFS_DISTINCT_Combinations(i + 1, s + 1); // ���� �������� �̵�
		}
	}
}

int main()
{
	sel = 3;
	//DFS_ALL_Combinations(0);
	//DFS_DISTINCT_Combinations(0, 0);
}