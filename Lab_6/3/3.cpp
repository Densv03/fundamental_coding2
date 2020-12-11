#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctime>
#include<iostream>
int num1, num2, ans, k, mistakes, mark, checker;
int main() {
	srand(time(0));
	for (int i = 0; i < 10; ++i) {
		num1 = rand() % 9 + 1;
		num2 = rand() % 9 + 1;
		printf("%d * %d = ", num1, num2);
		//scanf("%d", &k);

		checker = rand() % 10 + 1;
		if (checker <= 8) {
			k = num1 * num2;
			printf("%d\n", k);
		}
		else {
			k = rand() % 90 + 1;
			printf("%d\n", k);
		}

		if (num1 * num2 != k)mistakes++;
	}
	if (mistakes > 4)mark = 1;
	else mark = 5 - mistakes;
	printf("Your mark is %d", mark);
}