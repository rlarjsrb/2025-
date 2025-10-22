#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int num1, num2;

	printf("�� ������ �Է��ϼ��� (����: 0 0):\n");

	while (true) {
		int inputcount =scanf ("%d %d", &num1, &num2);

			if (inputcount != 2) {
				printf("�߸��� �Է��Դϴ�. ���� �� ���� ��Ȯ�� �Է��ϼ���.\n");

				while (getchar() != '\n');
				continue;
			}
		if (num1 == 0 && num2 == 0) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		if (num1 <= 0 || num2 <= 0) {
			printf("���α׷��� �����մϴ�.\n");
			continue;
		}

		int resultgcd = gcd(num1, num2);
		int resultlcm = lcm(num1, num2);

		printf("�ִ����� (gcd): %d\n", resultgcd);
		printf("�ּҰ���� (lcm): %d\n", resultlcm);
	}
	return 0;
}
