#include <iostream>
#include <string>

using namespace std;

int main() {
	string str = "abc123def456ghi";

	string numbers;

	// ���ڿ����� ���ڸ� �����Ͽ� numbers�� ����
	for (char c : str)
		if (c >= '0' && c <= '9')
			numbers += c;

	// ����� ���� ���
	cout << "����� ����: " << numbers << endl;

	// string�� int�� ��ȯ
	stoi(numbers);

	return 0;
}