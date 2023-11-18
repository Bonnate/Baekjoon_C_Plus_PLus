#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> numbers = { 1, 2, 3, 4, 5 };

	std::cout << "�̵� ��: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	std::rotate(numbers.begin(), numbers.begin() + 1, numbers.end());

	std::cout << "�̵� ��: ";
	for (int num : numbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}