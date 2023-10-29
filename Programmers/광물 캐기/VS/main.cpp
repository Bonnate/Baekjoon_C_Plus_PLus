#include <string>
#include <vector>
using namespace std;

int sel; // �����ؾ� �ϴ� ����
int ch[10]; // ���� �迭
bool used[10]; // �ش� id�� ����ߴ��� üũ
int answer = 99999; // answer
int stamina[3][3]{ {1, 1, 1},{5, 1, 1},{25, 5, 1} }; // �� ��̷� ĳ�� ������ �Ƿε� �Ҹ�

void DFS(vector<int> v1, vector<int> v2, int s)
{
	if (s == sel)
	{
		int sum = 0;

		// sel��ŭ �ݺ��Ͽ�
		for (int i = 0; i < sel; ++i)
		{
			// �� ��̸��� �ִ� 5���� ������ ķ
			for (int j = 0; j < 5; ++j)
			{
				// ���� ������ �ִ� ������ �Ѿ�� ����
				if (i * 5 + j >= v2.size())
					break;

				// �� ����� ä�� �Ƿε���ŭ�� ���ϱ�
				sum += stamina[v1[ch[i]]][v2[i * 5 + j]];
			}
		}

		// ������ ���� (�ּҰ�)
		answer = min(answer, sum);
	}
	else
	{
		// 0���� sel��ŭ �ݺ��Ͽ�
		for (int i = 0; i < sel; ++i)
		{
			// used[i]�� ������� �ʾҴٸ�
			if (!used[i])
			{
				used[i] = true; // ��� üũ
				ch[s] = i; // ����ch�� i�� ���
				DFS(v1, v2, s + 1); // DFS
				used[i] = false; // DFS�� ������ ��� üũ ����
			}
		}
	}
}

int solution(vector<int> picks, vector<string> minerals)
{
	// �����ؾ��ϴ� ������ ������ ����(5���) ��ŭ
	sel = minerals.size() / 5 + (minerals.size() % 5 == 0 ? 0 : 1);

	// v1�� ���� ���� ��̸� ����ϵ��� ����
	vector<int> v1;
	for (int i = 0; i < sel; ++i)
	{
		// ���̾Ƹ�� ��̺��� ���� �õ�
		if (picks[0] > 0)
		{
			--picks[0];
			v1.push_back(0);
		}
		else if (picks[1] > 0)
		{
			--picks[1];
			v1.push_back(1);
		}
		else if (picks[2] > 0)
		{
			--picks[2];
			v1.push_back(2);
		}
	}

	// sel�� ��̿� ������ �°� �����ĵ� �� ����
	// (������ 11��, ��̰� 2���ΰ�� sel�� 2�� �缳��)
	sel = v1.size();

	// v2�� stamina �迭���� ������ �����ϱ� ���� int�� ��ȯ
	vector<int> v2;
	for (string s : minerals)
	{
		if (s == "diamond")
			v2.push_back(0);
		else if (s == "iron")
			v2.push_back(1);
		else
			v2.push_back(2);
	}
	DFS(v1, v2, 0);

	return answer;
}

int main()
{
	solution({ 0, 1, 1 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}