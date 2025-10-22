#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "����� ������ �ܼ��� �Է��ϼ��� (2~9), ��ü ����� 'all �Ǵ� ��ü': ";
    cin >> input;

    if (input == "all" || input == "��ü") {
        for (int dan = 2; dan <= 9; dan++) {
            cout << "\n[" << dan << "��]" << endl;
            for (int i = 1; i <= 9; i++) {
                cout << dan << " x " << i << " = " << dan * i << endl;
            }
        }
    }
    else {
        try {
            int dan = stoi(input);  // ���ڿ��� ������ ��ȯ
            if (dan >= 2 && dan <= 9) {
                cout << "\n[" << dan << "��]" << endl;
                for (int i = 1; i <= 9; i++) {
                    cout << dan << " x " << i << " = " << dan * i << endl;
                }
            }
            else {
                cout << " 2���� 9 ������ ���ڸ� �Է��ϼ���." << endl;
            }
        }
        catch (...) {
            cout << " ����(2~9) �Ǵ� '��ü'�� �Է��ϼ���." << endl;
        }
    }

    return 0;
}
