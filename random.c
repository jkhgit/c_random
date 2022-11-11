#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define RANGE 1000
#define AMOUNT 5

int main(void)
{
	int key;
	int value[AMOUNT];

	srand((unsigned int)time(NULL));

	for (key = 0; key < AMOUNT; key++) {
		value[key] = (rand() % RANGE) + 1;
		for (int i = 0; i < key - 1; i++) {
			if (value[key] == value[i]) {
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < AMOUNT; i++) {
		for (key = 0; key < AMOUNT - 1; key++) {
			if (value[key] > value[key + 1]) {
				int tmp = value[key];
				value[key] = value[key + 1];
				value[key + 1] = tmp;
			}
		}
	}

	printf("\n\n생성된 번호는 [");
	for (key = 0; key < AMOUNT; key++) {
		printf("%d ", value[key]);
	}
	printf("] 입니다\n");

	system("sleep 1");
	return 0;
}
