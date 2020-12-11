#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<ctime>
#include<iostream>
int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int k = 0, k1 = 0;

	while (k != -1) {
		printf("Enter number of mashrooms: ");
		scanf("%d", &k);
		k1 = k;
		while (k >= 100)
			k /= 10;
		if (k % 10 == 0 || k % 10 >= 5 || (k >= 11 && k <= 20))printf("%d грибов\n", k1);
		else if (k % 10 == 1)printf("%d гриб\n", k1);
		else if (k % 10 == 2 || k % 10 == 3 || k % 10 == 4)printf("%d гриба\n", k1);
	}
	/*
	srand(time(0));
	for (int i = 0; i < 100; ++i) {
		k = rand() % 500 + 1;
		if (k % 10 == 0 || k % 10 >= 5 || (k >= 11 && k <= 20))printf("%d грибов\n", k);
		else if (k % 10 == 1)printf("%d гриб\n", k);
		else if (k % 10 == 2 || k % 10 == 3 || k % 10 == 4)printf("%d гриба\n", k);
	}
	*/
}