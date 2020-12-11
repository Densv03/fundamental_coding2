#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main() {
	printf("Do you want enter array from keyboard? Enter either 1 if you want or 0 if don't: ");
	int checker;
	scanf("%d", &checker);
	while (checker != 1 && checker != 0) {
		printf("You've entered incorrect number. Try again: ");
		scanf("%d", &checker);
	}
	int n, m, A[20][20];
	if (checker == 1) {
		printf("Enter array height (less than 20): ");
		scanf("%d", &n);
		printf("Enter array width (less than 20): ");
		scanf("%d", &m);
		while (n <= 0 && n > 20 || m >= 0 && m > 20) {
			printf("You've entered incorrect data. Try again\n");
			printf("Enter array height (less than 20): ");
			scanf("%d", &n);
			printf("Enter array width (less than 20): ");
			scanf("%d", &m);
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", A[i][j]);
	}
	else {
		srand(time(0));
		n = rand() % 5 + 1;
		m = rand() % 5 + 1;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				A[i][j] = rand() % 50 + 1;
		printf("Height = %d\nWidth = %d\nArray:\n", n, m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j)
				printf("%d ", A[i][j]);
			printf("\n");
		}
	}
	// Outputting original array

	printf("\n\n\nOriginal array:\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	// Copying array A to array B

	int mx = INT_MIN, pos = 0, B[20][20];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			B[i][j] = A[i][j];
	//Counting array A

	for (int i = 0; i < n; ++i) {
		mx = INT_MIN;
		for (int j = 0; j < m; ++j) {
			if (A[i][j] > mx) {
				pos = j;
				mx = A[i][j];
			}
		}
		swap(A[i][pos], A[i][0]);
	}
	// Outputting array A

	printf("\nArray A:\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	//Counting array B
	int pos_i = 0, pos_j = 0;
	int mn = INT_MAX;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (B[i][j] < mn) {
				mn = B[i][j];
				pos = i;
			}
		}
		//printf("\n%d %d %d\n", mn, pos_i, pos_j);
		swap(B[pos][j], B[n - 1][j]);
		mn = INT_MAX;
	}
	// Outputting array B

	printf("\nArray B:\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%d ", B[i][j]);
		printf("\n");
	}
}