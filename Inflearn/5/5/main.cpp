#include <iostream>

int main(int argc, const char* argv[]) {

    // �ֹε�Ϲ�ȣ ��, �� ��
    int first, last;

    // �ֹε�� ��ȣ�� �������� �Է� �ޱ�
    scanf("%d-%d", &first, &last);

    // birthYear�� first���� �� �α���
    int birthYear = first / 10000;
    // sex�� last���� �� �ѱ���
    int sex = last / 1000000;

    // ���� �Է��� 3, 4�̸� 2000����, 1, 2�̸� 1900����
    int age = 2019 - birthYear + 1 - (sex < 3 ? 1900 : 2000);
    bool isMale = sex % 2;

    printf("%d %c", age, isMale ? 'M' : 'W');

    return 0;
}