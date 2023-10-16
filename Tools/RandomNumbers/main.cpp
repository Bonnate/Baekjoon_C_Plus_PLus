#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <filesystem>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

// ���� �̸��� �����ϴ� �Լ�
string generateFilename(int creationType, bool isInteger, int count) {
	string creationTypeStr;
	if (creationType == 1) {
		creationTypeStr = "������";
	}
	else if (creationType == 2) {
		creationTypeStr = "��������";
	}
	else if (creationType == 3) {
		creationTypeStr = "��������";
	}

	string dataTypeStr = isInteger ? "����" : "�Ǽ�";

	string timestamp = to_string(time(0));
	return "RandomNumbers_" + creationTypeStr + "_" + dataTypeStr + "_" + timestamp + "_" + to_string(count) + "_" + ".txt";
}

int main() {
	// ���� �۾� ���丮 ���
	string currentDirectory = filesystem::current_path().string();

	// �õ�(seed) ����
	srand(static_cast<unsigned>(time(0)));

	int n;  // ������ ���� ����
	cout << "���� ������ �Է��ϼ���: ";
	cin >> n;

	// �ּҰ� �� �ִ밪 �Է�
	double minValue, maxValue;
	cout << "�ּҰ�: ";
	cin >> minValue;
	cout << "�ִ밪: ";
	cin >> maxValue;

	// ���� �Ǵ� �Ǽ� ���� �Է�
	bool isInteger;
	cout << "������ �����Ϸ��� 1, �Ǽ��� �����Ϸ��� 0�� �Է��ϼ���: ";
	cin >> isInteger;

	// ���� �Ӽ� ����
	int creationType;
	cout << "�Ӽ� ����: (1) ������ (2) �������� (3) ��������: ";
	cin >> creationType;

	// ���� �̸� ����
	string filename = generateFilename(creationType, isInteger, n);
	string filePath = currentDirectory + "\\" + filename;

	// ���� ����
	ofstream outputFile(filePath);

	if (!outputFile) {
		cerr << "������ �� �� �����ϴ�." << endl;
		return 1;
	}

	// ���� ���� ���� ����
	if (creationType == 1) {
		// ������ ����
		vector<double> random_numbers;
		if (isInteger) {
			uniform_int_distribution<int> distribution(static_cast<int>(minValue), static_cast<int>(maxValue));
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				int random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}
		}
		else {
			uniform_real_distribution<double> distribution(minValue, maxValue);
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				double random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}

			// ���͸� �������� ����
			random_device rd;
			shuffle(random_numbers.begin(), random_numbers.end(), mt19937(rd()));
		}

		for (int i = 0; i < n; i++) {
			outputFile << random_numbers[i];
			if (i < n - 1) {
				outputFile << ' ';
			}
		}
	}
	else if (creationType == 2) {
		// ��������
		if (isInteger) {
			uniform_int_distribution<int> distribution(static_cast<int>(minValue), static_cast<int>(maxValue));
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				int random_number = distribution(generator);
				outputFile << random_number;
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
		else {
			uniform_real_distribution<double> distribution(minValue, maxValue);
			mt19937 generator(time(0));
			vector<double> random_numbers;
			for (int i = 0; i < n; i++) {
				double random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}
			sort(random_numbers.begin(), random_numbers.end());

			for (int i = 0; i < n; i++) {
				outputFile << random_numbers[i];
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
	}
	else if (creationType == 3) {
		// ��������
		if (isInteger) {
			uniform_int_distribution<int> distribution(static_cast<int>(minValue), static_cast<int>(maxValue));
			mt19937 generator(time(0));
			for (int i = 0; i < n; i++) {
				int random_number = distribution(generator);
				outputFile << random_number;
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
		else {
			uniform_real_distribution<double> distribution(minValue, maxValue);
			mt19937 generator(time(0));
			vector<double> random_numbers;
			for (int i = 0; i < n; i++) {
				double random_number = distribution(generator);
				random_numbers.push_back(random_number);
			}
			sort(random_numbers.rbegin(), random_numbers.rend());

			for (int i = 0; i < n; i++) {
				outputFile << random_numbers[i];
				if (i < n - 1) {
					outputFile << ' ';
				}
			}
		}
	}

	// ���� �ݱ�
	outputFile.close();

	cout << "������ " << filename << "�� ����Ǿ����ϴ�." << endl;

	return 0;
}