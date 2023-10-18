#include <iostream>

/*
	nCr �� (n-1 C r-1) + (n-1 C r)�� ���� �� �ִ�.

	n==r�� �ǰų�, r�� 0�� �Ǹ�, ����� ���� 1�� ������ �� �ִ�.
	������� 5C5�� 5C0�� 1�̴�.
*/

// �޸������̼� (���� ���� ����صα�)
int dy[21][21];

int DFS(int N, int R)
{
	// �̹� dy�� ���� �ִٸ� �ٷ� �����ϱ�
	if (dy[N][R] > 0) return dy[N][R];

	else if (N == R || R == 0) return 1;

	// N,R�� N-1,R-1�� N-1,R�� �ɰ��� ���
	else return dy[N][R] = DFS(N - 1, R - 1) + DFS(N - 1, R);
}

int main()
{
	int N, R;
	scanf_s("%d %d", &N, &R);

	printf("%d", DFS(N, R));
}