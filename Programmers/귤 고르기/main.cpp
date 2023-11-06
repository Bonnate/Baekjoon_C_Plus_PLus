#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
	map<int, int> m;

	for (int n : tangerine)
		++m[n];

	// �켱���� ť�� �̿��Ͽ� ���� ���� ������ �����ͺ��� ��������
	priority_queue<pair<int, int>> q;
	for (pair<int, int> p : m)
		q.push({ -p.second, p.first });

	// left: �����ؾ� �� ���� ����
	int left = tangerine.size() - k;
	for (int i = 0; i < tangerine.size() - k; ++i)
	{
		// ���� ������ ���� ����
		int cnt = -q.top().first;

		// left�� ���� �������� ���ϴ°�� ����
		if (cnt > left)
			break;
		// ���� �����Ѱ�쿡�� ť���� pop
		else
		{
			left -= cnt;
			q.pop();
		}
	}

	return q.size();
}

int main()
{
	//solution(6, { 1, 3, 2, 5, 4, 5, 2, 3 });
	//solution(4, { 1, 3, 2, 5, 4, 5, 2, 3 });
	solution(2, { 1, 1, 1, 1, 2, 2, 2, 3 });
}