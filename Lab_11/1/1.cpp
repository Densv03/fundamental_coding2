#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<ctime>
int n, A[100];
int minimum(int k, int z[]) {
	return z[0];
}
using namespace std;
int main() {
	srand(time(0));
	printf("Do you want to enter array by youseflf? Enter either 1 or 0 (yes or no respectively): ");
	int checker;
	scanf("%d", &checker);
	while (checker != 0 && checker != 1) {
		printf("You've entered incorrect number. Try again: ");
		scanf("%d", &checker);
	}
	if (checker == 1) {
		printf("Enter array size: ");
		scanf("%d", &n);
		printf("Enter elements of array: ");
		for (int i = 0; i < n; ++i)
			scanf("%d", A[i]);
	}
	else {
		printf("Do you want to enter array size? Enter either 1 or 0 (yes or no respectively): ");
		int checker1;
		scanf("%d", &checker1);
		while (checker1 != 1 && checker1 != 0) {
			printf("You've entered incorrect data. Try again: ");
			scanf("%d", &checker1);
		}
		if (checker1 == 1) {
			printf("Enter array size: ");
			scanf("%d", &n);
			for (int i = 0; i < n; ++i)
				A[i] = rand() % 15 + 1;
		}
		else {
			n = rand() % 10 + 1;
			for (int i = 0; i < n; ++i)
				A[i] = rand() % 15 + 1;
		}
		printf("Original array:\n");
		for (int i = 0; i < n; ++i)
			printf("%d ", A[i]);
	}
	cout << '\n' << '\n' << minimum(n, A);
}