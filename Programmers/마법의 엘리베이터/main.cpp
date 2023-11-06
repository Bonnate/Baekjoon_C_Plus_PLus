#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
	int answer = 0;
	int digit = 1;

	while (true)
	{
		int front = storey % 100 / 10;
		int back = storey % 10;

		if (back != 5)
		{
			if (back > 5)
				storey += 10, answer += (10 - back);
			else
				answer += back;
		}
		else if (front >= 5) // back�� 5�϶� front�� 5���� ũ��?
			answer += (10 - back), storey += 10;
		else // back�� 5�϶� front�� ���϶��?
			answer += back;

		storey /= 10;

		if (storey < 10)
		{
			if (storey < 6)
				answer += storey;
			else
				answer += (10 - storey + 1);
			break;
		}
	}

	return answer;
}

int main()
{
	solution(5555);
}