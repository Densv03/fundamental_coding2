#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<ctime>
char comparative(int x, int y) {
	if (x == y)
		return '=';
	else if (x > y)
		return '>';
	else
		return '<';
}
using namespace std;
int main() {
	int a, b, checker;
	printf("Do you want to enter numbers from keyboard? Enter either 1 or 0 (yes or no respectively): ");
	scanf("%d", &checker);
	while (checker != 1 && checker != 0) {
		printf("You've entered incorrect number. Try again: ");
		scanf("%d", &checker);
	}
	if (checker == 1) {
		printf("Enter first number: ");
		scanf("%d", &a);
		printf("Enter second number: ");
		scanf("%d", &b);
	}
	else {
		srand(time(0));
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		printf("a = %d\nb = %d\n", a, b);
	}
	printf("%c", comparative(a, b));
}