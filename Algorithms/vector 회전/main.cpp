#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<int> v{ 0, 1, 2, 3, 4, 5 };
	int depth = 1;

	for (int n : v)
		cout << n << " ";
	cout << endl;

	rotate(v.begin(), v.begin() + depth, v.end()); // �ε����� �����ϴ� �������� depth��ŭ ȸ��

	for (int n : v)
		cout << n << " ";
	cout << endl;

	rotate(v.rbegin(), v.rbegin() + depth, v.rend()); // �ε����� �����ϴ� �������� depth��ŭ ȸ��

	for (int n : v)
		cout << n << " ";
	cout << endl;

	return 0;
}