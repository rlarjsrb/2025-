#include <iostream>
using namespace std;

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
double divi(int a, int b);
int mod(int a, int b);

int main() {
	int num1, num2;

	cout << "�� ���� ������ �Է��ϼ���.";
	cin >> num1 >> num2;

	cout << "\n===== ��� =====" << endl;
	cout << "����: " << add(num1, num2) << endl;
	cout << "����: " << sub(num1, num2) << endl;
	cout << "����: " << mul(num1, num2) << endl;

	if (num2 = 0) {
		cout << "������: " << divi(num1, num2) << endl;
		cout << "������: " << mod(num1, num2) << endl;
	}
	else {
		cout << "�������� �������� 0���� ���� �� �����ϴ�." << endl;
	}
	return 0;
}

int add (int a, int b) {
	return a + b;
}
int sub (int a, int b) {
	return a - b;
}
int mul (int a, int b) {
	return a * b;
}
double divi (int a, int b) {
	return (double)a / b;
}
int mod (int a, int b) {
	return a % b;
}
