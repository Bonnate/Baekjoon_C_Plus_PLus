#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	vector<string> v = { "apple", "orange", "banana", "orange", "grape" };

	string _s = "orange";

	// ���Ϳ��� Ư�� �� ã��
	auto it = find(v.begin(), v.end(), _s);

	if (it != v.end()) {
		// ���� ã������ ����
		v.erase(it);
	}

	// ���� �� ���� ���
	for (const auto& element : v) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}