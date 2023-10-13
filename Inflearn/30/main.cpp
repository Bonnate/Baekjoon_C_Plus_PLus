#include <iostream>
#include <string>

using namespace std;
int main()
{
	int N;
	int cnt = 0;
	scanf_s("%d", &N);

	// �Է°��� ���ڿ���
	string str = to_string(N);

	// ���ڿ��� ������ŭ �ݺ�
	for (int i = str.length() - 1; i >= 0; --i)
	{
		int digit = pow(10, str.length() - 1 - i); // ���� center�� �ش��ϴ� �ڸ���

		int left = (i == 0) ? 0 : N / digit / 10; // center ���� ����
		int center = str[i] - '0'; // ���� ������ �ڸ����� �ش��ϴ� ��
		int right = (i == str.length() - 1) ? 0 : N % digit; // center ���� ������ ��

		if (center > 3) // center�� 3���� ũ�ٸ�?
		{
			cnt += (left + 1) * digit; // 3�� ����ϴ� ������ left ���� + 1 (�ڽ��� ����)
		}
		else if (center < 3) // center�� 3���� �۴ٸ�?
		{
			cnt += left * digit; // 3�� ����ϴ� ������ left ���� (�ڽ��� ����)
		}
		else // center�� 3�̶��?
		{
			cnt += left * digit + right + 1; // �ڽ��� ��� �������� �ʰ�, right ���� + 1��ŭ ����
		}
	}

	printf("%d", cnt);
}