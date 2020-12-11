#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;
int A[10][10], n = 9, counter = 1, k;
int main() {
	int shift = 0;
	printf("Enter n (n - matrix size): ");
	scanf("%d", &n);
	if (n % 2 != 0)A[n / 2][n / 2] = n * n;
	// General cycle
	for (int h = 0; h < n / 2; ++h) {
		// Filling in left side

		for (int i = shift; i < n - shift; ++i) {
			int j = shift;
			A[i][j] = counter;
			counter++;
		}
		// Filling in bottom

		int i = n - shift - 1;
		for (int j = shift + 1; j < n - shift; ++j) {
			A[i][j] = counter;
			counter++;
		}
		// Filling in right side

		int j = n - shift - 1;
		for (int i = n - shift - 2; i >= shift; --i) {
			A[i][j] = counter;
			counter++;
		}
		// Filling in top side

		i = shift;
		for (j = n - shift - 2; j >= shift + 1; j--) {
			A[i][j] = counter;
			counter++;
		}
		shift++;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}