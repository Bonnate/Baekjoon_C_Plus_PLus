#include <stdio.h>
#include <math.h>

int main()
{
	//�����佺�׳׽��� ü���� ����� �Ҽ� �Ǻ��� �� �迭
	bool* flag;

	//�ּҺ��� �ִ���� �־��� ��� �Է��ϴ� ����
	int m, n;

	//�� �Է�
	scanf_s("%d %d", &m, &n);

	//�ִ밪���� �����Ҵ������� �迭�� �����.
	//new bool[]()�� Zero-initialized�� ���� false�� ���·� ������ �� �ִ�.
	//���� �ּ� https://stackoverflow.com/questions/4262914/set-default-value-of-dynamic-array
	//�̷��� ������ ������ true�� ������ �� ������, O(n) �ð� ���⵵�� ���� true�� �ٲ�
	//���ʿ��� ó���� �ϴ°��� ��ȿ�����̶� �Ǵ��Ͽ���.
	flag = new bool[n + 1]();

	//1�� �Ҽ��� �ƴϴ� -> ������ �ٲ� ��µ��� �ʰ��Ѵ�.
	flag[1] = true;
 
	//�Ҽ��� ã�µ� �ִ밪�� �����ٱ��� �˻��Ѵ�.
	for (int i = 2; i <= sqrt(n); ++i)
	{
		//i�� �Ҽ��ΰ�?
		if(!flag[i])
		{
			//i�� n��� ��� �Ҽ��� �ƴϹǷ� true�� �ٲ��ش�.
			for (int j = i * 2; j <= n; j += i)
			{
				flag[j] = true;
			}
		}
	}

	//true�� �ƴ� ��� ������ �Ҽ��� �ƴѰ����� ��Ÿ����.
	for (int i = m; i <= n; ++i)
	{
		if (!flag[i]) printf("%d\n", i);
	}
}