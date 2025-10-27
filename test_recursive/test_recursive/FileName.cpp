#include <iostream>
using namespace std;

#define NUM_PRINT 5

void PrintHelloWorld(int nCount);

int main() {
    int nCount = 0;
    PrintHelloWorld(nCount);
    return 0;
}

void PrintHelloWorld(int nCount) {
    if (nCount == NUM_PRINT) {
        return;
    }
    cout << "Hello, World!(" << nCount << ")\n";
    PrintHelloWorld(++nCount);
    cout << "jam\n";
}