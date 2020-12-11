#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<ctime>
int main() {
	int comp_number, user_number, attempts = 0;
	srand(time(0));
	comp_number = rand() % 10 + 1;
	//printf("%d\n", comp_number);
	while (true) {
		printf("Enter number: ");
		scanf("%d", &user_number);
		attempts++;
		if (comp_number > user_number)printf("My number is more\n");
		else if (comp_number < user_number)printf("My number is less\n");
		else {
			printf("Congratulations! It took %d attempts", attempts);
			break;
		}
	}
}