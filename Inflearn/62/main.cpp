#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[101], tmp[101];
void divide(int lt, int rt) {
	int mid;
	int p1, p2, p3;
	if (lt < rt) {
		mid = (lt + rt) / 2;

		// ���� ��� ����
		divide(lt, mid);
		// ������ ��� ����
		divide(mid + 1, rt);

		/* �ڽ� ��尡 ��� ���ҵǰų�, �� �̻� �ڽĳ�尡 ���ٸ� ? */

		// ������ �˻��� ������
		p1 = lt; // ���� ��� ����
		p2 = mid + 1; // ���� ��� ����
		p3 = lt; // ���ʴ�� ���� ä�� �ε��� ��ȣ

		// p1�� �߰��� �Ѿ�ų�, p2�� ���� �����Ҷ����� �ݺ�
		while (p1 <= mid && p2 <= rt)
		{
			// p1�� p2���� �۴ٸ�? (���� ����� ������ ��Ϻ��� ����)
			if (a[p1] < a[p2])
				tmp[p3++] = a[p1++]; // p1��°�� ���� tmp[p3]�� ����
			else
				tmp[p3++] = a[p2++]; // p2��°�� ���� tmp[p3]�� ����
		}

		// p1, p2 �� ������� ���� �������� �����Ͽ� ä���
		while (p1 <= mid)
			tmp[p3++] = a[p1++]; // ��� ����
		while (p2 <= rt)
			tmp[p3++] = a[p2++]; // ��� ����

		// ���� ���� ����
		for (int i = lt; i <= rt; i++) {
			a[i] = tmp[i];
		}
	}
}

int main() {
	int n, i;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &a[i]);
	}
	divide(1, n);
	for (i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}