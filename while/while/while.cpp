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

	printf("두 정수를 입력하세요 (종료: 0 0):\n");

	while (true) {
		int inputcount =scanf ("%d %d", &num1, &num2);

			if (inputcount != 2) {
				printf("잘못된 입력입니다. 숫자 두 개를 정확히 입력하세요.\n");

				while (getchar() != '\n');
				continue;
			}
		if (num1 == 0 && num2 == 0) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		if (num1 <= 0 || num2 <= 0) {
			printf("프로그램을 종료합니다.\n");
			continue;
		}

		int resultgcd = gcd(num1, num2);
		int resultlcm = lcm(num1, num2);

		printf("최대공약수 (gcd): %d\n", resultgcd);
		printf("최소공배수 (lcm): %d\n", resultlcm);
	}
	return 0;
}
