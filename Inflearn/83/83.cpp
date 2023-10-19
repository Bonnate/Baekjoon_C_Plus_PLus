#include <iostream>

// S E N D M O R Y
// �� �ε��� ��ȣ���� ���� �ش��ϴ� ���ڷ� ���ֵǾ� ���
int arr[8];

// 0���� 9������ ����ߴ��� üũ
bool ch[10];

int SEND()
{
	// arr�� �� �ε��� ��ȣ�� �ش��ϴ´�� ���ڸ� ���ڷ� ���
	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3] * 1;
}

int MORE()
{
	return arr[4] * 1000 + arr[5] * 100 + arr[6] * 10 + arr[1] * 1;
}

int MONEY()
{
	return arr[4] * 10000 + arr[5] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[7] * 1;
}

void DFS(int cnt)
{
	if (cnt == 8)
	{
		if (SEND() + MORE() == MONEY())
		{
			// ���� S, M�� �ڸ��� 0�̶�� ����
			if (arr[0] == 0 || arr[4] == 0)
				return;

			// �� ���
			printf("  %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
			printf("+ %d %d %d %d\n", arr[4], arr[5], arr[6], arr[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", arr[4], arr[5], arr[2], arr[1], arr[7]);

			exit(0);
		}
	}
	else
	{
		// 0���� 9���� ������ ���� ������ �ݺ�
		for (int i = 0; i < 10; ++i)
		{
			// ���� i�� ������� �ʾҴٸ�?
			if (!ch[i])
			{
				// arr[cnt]�� i
				arr[cnt] = i;

				// ���� i ��� �Ϸ�
				ch[i] = true;

				// ��� ȣ��
				DFS(cnt + 1);

				// ���� i ��� ����
				ch[i] = false;
			}
		}
	}
}

int main()
{
	DFS(0);
}