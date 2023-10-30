#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getTime(string format)
{
	return stoi(format.substr(0, 2)) * 60 + stoi(format.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
	// pair�� �Խ�, ���(û�� �ð� ����)�� ����
	vector<pair<int, int>> v;
	for (vector<string> s : book_time)
		v.push_back({ getTime(s[0]) , getTime(s[1]) + 10 });

	// ���� ����(�Խ� �ð� ��������)
	sort(v.begin(), v.end());

	// �켱���� ť�� �̿��Ͽ� �˻�
	priority_queue<int> q;
	for (int i = 0; i < v.size(); ++i)
	{
		// ť���� v[i].first(���� �ð�)�� q.top �̻��̶��?
		if (!q.empty() && -q.top() <= v[i].first)
			q.pop(); // ������ ���� ��� �����ϱ⿡ pop�� �Ͽ� ť���� ����

		// ���ο� �� ��� (pop�� �� ��� ȣ��Ǵ°�쿡��, pop�� �� ���� û�� �� ����
		q.push(-v[i].second);
	}

	// ť�� size�� �ּҷ� ����ؾ��ϴ� ���� ����
	return q.size();
}

int main()
{
}