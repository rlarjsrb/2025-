#include <stdio.h>

struct MyStruct {
    char ch;    
    int n;      
    double d;   
};

union MyUnion {
    char ch;    
    int n;      
    double d;  
};

int main(void) {
    struct MyStruct s1;
    union MyUnion u1;

    printf("== 1. 메모리 크기 비교 ==\n");

    printf("구조체(MyStruct)의 크기: %zu 바이트\n", sizeof(s1));

    printf("공용체(MyUnion)의 크기 : %zu 바이트\n\n", sizeof(u1));

    printf("== 2. 멤버들의 주소 비교 ==\n");
    printf("구조체 - ch: %p, n: %p, d: %p (주소가 다름)\n", (void*)&s1.ch, (void*)&s1.n, (void*)&s1.d);
    printf("공용체 - ch: %p, n: %p, d: %p (주소가 같음)\n\n", (void*)&u1.ch, (void*)&u1.n, (void*)&u1.d);

    printf("== 3. 데이터 조작 테스트 ==\n");

    s1.n = 100;
    s1.d = 3.14;
    printf("[구조체] n: %d, d: %.2f (모두 정상 출력)\n", s1.n, s1.d);

    u1.n = 100;
    printf("[공용체] n에 100 대입 후: %d\n", u1.n);

    u1.d = 3.14; 
    printf("[공용체] d에 3.14 대입 후:\n");
    printf("  -> u1.d: %.2f (정상)\n", u1.d);
    printf("  -> u1.n: %d (쓰레기값 출력됨 - 메모리가 덮어씌워졌기 때문)\n", u1.n);

    return 0;
}