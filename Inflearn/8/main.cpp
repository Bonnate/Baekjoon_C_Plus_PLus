#include <iostream>
#include <cstring>

int main()
{
	char input[31];
	scanf_s("%s", input, sizeof(input));

	int left = 0, right = 0;
	int inputLen = strlen(input);

	// ��ȣ�� ������ Ȧ�����?
	if (inputLen % 2 == 1)
	{
		printf("NO");
		return 0;
	}

	// ��ȣ�� �� ���� �߸��Ǿ��ٸ�?
	if (input[0] == ')' || input[inputLen - 1] == '(')
	{
		printf("NO");
		return 0;
	}

	for (int i = 0; input[i] != '\0'; ++i)
		if (input[i] == '(')
			++left;
		else if (input[i] == ')')
			++right;

	printf("%s", left == right ? "YES" : "NO");
}