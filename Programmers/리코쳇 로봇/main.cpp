#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int dx[4]{ -1, 1, 0, 0 };
int dy[4]{ 0, 0, -1, 1 };

int solution(vector<string> board) {
	int width = board[0].size();
	int height = board.size();

	// ť
	stack<pair<int, int>> q;

	// �Ÿ��� ����
	vector<vector<int>> v(vector<vector<int>>(height, vector<int>(width, 999)));

	// ����, ���� ���� ����
	pair<int, int> start{ -1, -1 }, end{ -1, -1 };
	for (int i = 0; i < height; ++i)
		if (start.first != -1 && end.first != -1)
			break;
		else
			for (int j = 0; j < width; ++j)
				if (board[i][j] == 'R')
					start = { i, j };
				else if (board[i][j] == 'G')
					end = { i, j };

	q.push(start);
	v[start.first][start.second] = 0;
	while (!q.empty())
	{
		int x = q.top().second;
		int y = q.top().first;
		q.pop();

		printf("������ġ: %d %d\n", y, x);

		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			// �����¿� ������ ��ĭ �̻� �� �� �ִ��� Ȯ��
			if (xx == -1 || yy == -1 || xx == width || yy == height || board[yy][xx] == 'D')
			{
				printf("%d %d���� %d %d�� �� �� ����!\n", y, x, yy, xx);
				continue;
			}

			// �� �� �ִ� ���⿡�� �ִ�� �̵�
			int xxx = x;
			int yyy = y;
			while (true)
			{
				xxx += dx[i];
				yyy += dy[i];

				if (xxx == -1 || yyy == -1 || xxx == width || yyy == height || board[yyy][xxx] == 'D')
				{
					xxx -= dx[i];
					yyy -= dy[i];

					// ������ �湮�� �Ÿ����� ª�� �Ÿ��� �����ߴٸ�?
					// �ش� ��ġ�� ª�� �Ÿ��� �ٽ� �����Ͽ� �ٽ� �������
					if (v[yyy][xxx] > v[y][x] + 1)
					{
						q.push({ yyy, xxx });
						printf("%d %d���� %d %d�� �̵�!\n", y, x, yyy, xxx);
						v[yyy][xxx] = v[y][x] + 1;
					}

					break;
				}
			}
		}
	}

	return v[end.first][end.second] == 999 ? -1 : v[end.first][end.second];
}

int main() {
	//cout << solution({
	//	"...D..R",
	//	".D.G...",
	//	"....D.D",
	//	"D....D.",
	//	"..D...." });
	cout << solution({
		".D.R",
		"....",
		".G..",
		"...D" });
}