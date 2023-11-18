#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> v = { 1, 2, 3, 3, 3, 3, 5, 6, 7, 8, 9 };

	bool found = binary_search(v.begin(), v.end(), 3);

	cout << "���� ���� ��: ";
	for (int n : v)
		cout << n << " ";
	cout << endl;

	if (found) {
		cout << "3�� ������" << endl;
	}
	else {
		cout << "3�� �������� ����!" << endl;
	}

	auto it_lower = lower_bound(v.begin(), v.end(), 3);

	if (it_lower != v.end()) {
		printf("3 �̻��� ó������ ��Ÿ���� �ε��� ��ġ: %d, ��: %d\n", distance(v.begin(), it_lower), *it_lower);
	}
	else {
		cout << "3 �̻��� ��Ÿ���� ��ġ�� ã�� ����!" << endl;
	}

	auto it_upper = upper_bound(v.begin(), v.end(), 3);

	if (it_upper != v.end()) {
		printf("3���� ū ���� ó������ ��Ÿ���� �ε��� ��ġ: %d, ��: %d\n", distance(v.begin(), it_upper), *it_upper);
	}
	else {
		cout << "3���� ū ���� ��Ÿ���� ��ġ�� ã�� ����!" << endl;
	}

	return 0;
}