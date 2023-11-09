#include <iostream>
#include <vector>
using namespace std;

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
		// 0���� sel���� �ݺ�
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
/// �ߺ��� ���� ������ �̱�
/// </summary>
/// <param name="s">���� �� start</param>
/// <param name="p">���� ���� ��ġ place</param>
void DFS_Combinations(int s, int p)
{
	// position�� sel(�̾ƾ� �� �� ����)���?
	if (p == sel)
	{
		for (int i = 0; i < sel; ++i)
			printf("%c ", arr[ch[i]]);
		printf("\n");
	}
	else
	{
		// i�� ���� ���� �������� �����Ͽ� ������ ������ ������ �ݺ�
		for (int i = s; i < 4; ++i)
		{
			ch[p] = i; // s��° ������ ���� i��

			// i + 1�� start��, p + 1�� position�����Ͽ� ���� ��� ȣ��
			DFS_Combinations(i + 1, p + 1);
		}
	}
}

vector<int> combination; // ������� ���� ������ �����ϴ� �迭
void generateCombination(int start, int r, vector<int>& arr)
{
	// ���� ����: r���� ���Ҹ� ������ ���
	if (r == 0)
	{
		for (int n : combination)
			printf("%d ", n);
		printf("\n");
		return;
	}

	// ��� ȣ��
	for (int i = start; i < arr.size(); ++i)
	{
		combination.push_back(arr[i]); // ���� �ڿ� ����
		generateCombination(i + 1, r - 1, arr); // ������(i+1)���� �����ϰ�, r(�����ؾ��� ����)�� 1����
		combination.pop_back(); // �ڿ��� �� ����
	}
}

int main()
{
	sel = 4;

	DFS_ALL_Combinations(0); // sel���� ��� ����
}