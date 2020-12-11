#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<ctime>
using namespace std;
int n, m, o, p, checker = 0, A[50][50], B[50][50], C[50][50];
int main() {
	printf("Do you want to enter matrix size from keyboard? Enter either 1 if you want or 2 if you don't: ");
	scanf("%d", &checker);
	while (checker != 1 && checker != 2) {
		printf("You've entered incorrect data. Try again: ");
		scanf("%d", &checker);
	}
	if (checker == 1) {
		printf("Enter first matrix size (all sizes must be less than 30)\nEnter height: ");
		scanf("%d", &m);
		printf("Enter width: ");
		scanf("%d", &n);
		printf("Enter second matrix size (all sizes must be less than 30)\nEnter height: ");
		scanf("%d", &o);
		printf("\nEnter width: ");
		scanf("%d", &p);
		while (n != o || m > 30 || n > 30 || o > 30 || p > 30) {
			printf("You entered incorrect sizes. Try again\nEnter first matrix size (all sizes must be less than 30) \nEnter height: ");
			scanf("%d", &m);
			printf("Enter width: ");
			scanf("%d", &n);
			printf("Enter second matrix size (all sizes must be less than 30)\nEnter height: ");
			scanf("%d", &o);
			printf("Enter width: ");
			scanf("%d", &p);
		}
		printf("Enter first array elements: ");
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &A[i][j]);
		printf("Enter second array elements: ");
		for (int i = 0; i < o; ++i)
			for (int j = 0; j < p; ++j)
				scanf("%d", &B[i][j]);
	}
	else {
		srand(time(0));
		m = rand() % 4 + 1;
		n = rand() % 4 + 1;
		o = n;
		p = rand() % 4 + 1;
		printf("Generates matrix sizes are:\nm = %d\nn = %d\no = %d\np = %d\n", m, n, o, p);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				A[i][j] = rand() % 2 + 1;
		for (int i = 0; i < o; i++)
			for (int j = 0; j < p; ++j)
				B[i][j] = rand() % 2 + 1;
		printf("First matrix that we have:\n");
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j)
				printf("%d ", A[i][j]);
			printf("\n");
		}
		printf("Second matrix that we have:\n");
		for (int i = 0; i < o; ++i) {
			for (int j = 0; j < p; ++j)
				printf("%d ", B[i][j]);
			printf("\n");
		}
	}
	// Starting calculate

	int k = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < p; ++j) {
			while (k != m) {
				C[i][j] += A[i][k] * B[k][j];
				k++;
			}
			k = 0;
		}
	}

	cout << "Result: " << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < p; ++j)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}