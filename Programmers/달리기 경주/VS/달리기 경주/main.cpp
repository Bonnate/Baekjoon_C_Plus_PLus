#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
	vector<string> answer;

	// �ΰ��� map�� ����Ͽ� swap
	unordered_map<int, string> m1;
	unordered_map<string, int> m2;

	// map�� ��� ���� ����
	for (int i = 0; i < players.size(); i++)
	{
		m1[i] = players[i];
		m2[players[i]] = i;
	}

	// calling ��ŭ �ݺ�
	for (int i = 0; i < callings.size(); i++)
	{
		// ���� �̸��� ����Ű�� �ε��� ��ȣ�� ������ ��������
		int currentIdx = m2[callings[i]];

		// callings[1]���� ��ĭ �տ� �ִ� ����� ��������
		string change = m1[currentIdx - 1];

		// m1�� �յڷ� ����
		m1[currentIdx - 1] = callings[i];
		m1[currentIdx] = change;

		// m2�� �յڷ� ����
		m2[callings[i]] = currentIdx - 1;
		m2[change] = currentIdx;
	}

	// foreach���� �����ߴ� ������� �����ϱ⿡ 1����� ����
	for (pair<int, string> p : m1)
	{
		cout << p.second << endl;
		answer.push_back(p.second);
	}

	return answer;
}

int main(int argc, const char* argv[]) {
	solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

	return 0;
}