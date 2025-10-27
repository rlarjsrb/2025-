#include <iostream>
using namespace std;

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
double divi(int a, int b);
int mod(int a, int b);

int main() {
	int num1, num2;

	cout << "µÎ °³ÀÇ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä.";
	cin >> num1 >> num2;

	cout << "\n===== °á°ú =====" << endl;
	cout << "µ¡¼À: " << add(num1, num2) << endl;
	cout << "»¬¼À: " << sub(num1, num2) << endl;
	cout << "°ö¼À: " << mul(num1, num2) << endl;

	if (num2 = 0) {
		cout << "³ª´°¼À: " << divi(num1, num2) << endl;
		cout << "³ª¸ÓÁö: " << mod(num1, num2) << endl;
	}
	else {
		cout << "³ª´°¼À°ú ³ª¸ÓÁö´Â 0À¸·Î ³ª´­ ¼ö ¾ø½À´Ï´Ù." << endl;
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
