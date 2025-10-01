#include <stdio.h>

int main(void)
{
    char name[50];
    int studentID;
    float height_cm, height_m, weight, bmi;

    // 사용자에게 입력 안내
    printf("이름, 학번, 키(cm), 몸무게(kg)를 입력하세요:\n");

    // Visual Studio에서는 scanf_s 사용 (문자열 입력에는 크기 명시 필요)
    scanf_s("%s %d %f %f", name, (unsigned)_countof(name), &studentID, &height_cm, &weight);

    // cm를 m로 변환
    height_m = height_cm / 100.0f;

    // BMI 계산
    bmi = weight / (height_m * height_m);

    // 출력
    printf("\n[입력 정보]\n");
    printf("이름: %s\n", name);
    printf("학번: %d\n", studentID);
    printf("키: %.2f m\n", height_m);
    printf("몸무게: %.2f kg\n", weight);

    printf("\n[BMI 결과]\n");
    printf("BMI: %.2f\n", bmi);

    return 0;
}
