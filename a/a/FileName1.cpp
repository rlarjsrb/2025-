#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void clear_input_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        ;
    }
}

int main(void)
{
    char str1[100];
    char str2[100];

    printf("Enter first string(no spaces): ");
    scanf("%99s", str1);

    printf("Enter second string(no spaces): ");
    scanf("%99s", str2);

    printf("\n---Printed strings (using puts)---\n");
    puts(str1);
    puts(str2);

    return 0;
}
