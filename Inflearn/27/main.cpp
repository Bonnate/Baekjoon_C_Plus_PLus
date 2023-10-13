#include <iostream>

using namespace std;

static bool primeArr[1001];
static int primes[1001];

int isPrime(int x);
void divide(int x);

int main()
{
	for (int i = 0; i < 1001; ++i)
		primes[i] = primeArr[i] = 0;

	int N;
	scanf_s("%d", &N);

	printf("%d! = ", N);

	for (int i = 2; i <= N; ++i)
		divide(i);

	for (int i = 2; i <= N; ++i)
		if (primeArr[i])
			printf("%d ", primes[i]);
}

void divide(int x)
{
	int primeIdx = isPrime(x);

	if (primeIdx == -1) // �Ҽ��� ����
	{
		++primes[x];
	}
	else if (x >= 2) // �Ҽ��� �ƴѰ��, ������
	{
		divide(x / primeIdx);
		divide(primeIdx);
	}
}

int isPrime(int x)
{
	// �̹� �Ҽ��� ��ϵǾ��ִٸ�, ��� ����
	if (primeArr[x])
		return -1;

	// �ش� ������ �������� �־� �Ҽ��� �ƴ�
	for (int i = 2; i <= sqrt(x); ++i)
		if (x % i == 0)
			return i;

	// �Ҽ��� �������� ���Ѱ��, x�� �Ҽ��� ����
	primeArr[x] = true;
	return -1;
}