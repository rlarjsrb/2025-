#include <stdio.h>

int main(void)
{
	int age = 24;
	unsigned int count = 300000000;
	float score = 93.5f;
	const char* title = "Basic Constants";
	const char* name = "Geongyu";
	char initial = name[0];
	printf("=== %s ===\n Name \t : %s\n initial : %c\n Age : %d\n Score \t : %.6f\n Count \t : %u\n", title, name, initial, age, score, count);
	return 0;
}
