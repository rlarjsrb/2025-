#include <stdio.h>

int main(void)
{
    char name[50];
    int studentID;
    float height_cm, height_m, weight, bmi;

    // ����ڿ��� �Է� �ȳ�
    printf("�̸�, �й�, Ű(cm), ������(kg)�� �Է��ϼ���:\n");

    // Visual Studio������ scanf_s ��� (���ڿ� �Է¿��� ũ�� ��� �ʿ�)
    scanf_s("%s %d %f %f", name, (unsigned)_countof(name), &studentID, &height_cm, &weight);

    // cm�� m�� ��ȯ
    height_m = height_cm / 100.0f;

    // BMI ���
    bmi = weight / (height_m * height_m);

    // ���
    printf("\n[�Է� ����]\n");
    printf("�̸�: %s\n", name);
    printf("�й�: %d\n", studentID);
    printf("Ű: %.2f m\n", height_m);
    printf("������: %.2f kg\n", weight);

    printf("\n[BMI ���]\n");
    printf("BMI: %.2f\n", bmi);

    return 0;
}
