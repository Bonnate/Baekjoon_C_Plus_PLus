#include <iostream>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	// ����� ����
	int cnt = N / M;

	// �ּҰ�
	int min = M;

	// �ִ밪 
	int max = N - N % M;

	// ��� (������ Ȧ���ΰ�� �߰� �� �����ֱ�)
	int sum = (min + max) * (cnt / 2) + (cnt % 2 == 1 ? (min + max) / 2 : 0);

	// ��� ���
	cout << sum;
}