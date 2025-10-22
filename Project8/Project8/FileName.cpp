#include <stdio.h>

using namespace std;

int main(void) 
{
    string input;
    cout << "출력할 구구단 단수를 입력하세요 (2~9), 전체 출력은 'all': ";
    cin >> input;

    if (input == "all" || input == "ALL") {
        for (int dan = 2; dan <= 9; dan++) {
            cout << "\n[" << dan << "단]" << endl;
            for (int i = 1; i <= 9; i++) {
                cout << dan << " x " << i << " = " << dan * i << endl;
            }
        }
    }
    else {
        try {
            int dan = stoi(input);  // 문자열을 정수로 변환
            if (dan >= 2 && dan <= 9) {
                cout << "\n[" << dan << "단]" << endl;
                for (int i = 1; i <= 9; i++) {
                    cout << dan << " x " << i << " = " << dan * i << endl;
                }
            }
            else {
                cout << "⚠️ 2부터 9 사이의 숫자를 입력하세요." << endl;
            }
        }
        catch (...) {
            cout << "⚠️ 숫자(2~9) 또는 'all'을 입력하세요." << endl;
        }
    }

    return 0;
}
