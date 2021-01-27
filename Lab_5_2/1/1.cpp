#include<iostream>
#include<Windows.h>
#include<iomanip>
#include"head.h"
using namespace std;
#define TYPE 2
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, counter = 1, k, shift = 0;
	cout << "Введите размер массива: ";
	cin >> n;
#if TYPE==1
	int** A;
	A = new int* [n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[n];
	if (n % 2)A[n / 2][n / 2] = n * n;
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
			cout << setw(dights(n * n)) << A[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[]A[i];
	delete[]A;
#else
	int* A = new int[n * n];
	if (n % 2)
		A[((n / 2) * n) + ((n / 2) + 1)] = n * n;
	for (int h = 0; h < n / 2; ++h) {
		// Filling in left side

		for (int i = shift; i < n - shift; ++i) {
			int j = shift;
			A[i * n + j + 1] = counter;
			counter++;
		}
		// Filling in bottom

		int i = n - shift - 1;
		for (int j = shift + 1; j < n - shift; ++j) {
			A[i * n + j + 1] = counter;
			counter++;
		}
		// Filling in right side

		int j = n - shift - 1;
		for (int i = n - shift - 2; i >= shift; --i) {
			A[i * n + j + 1] = counter;
			counter++;
		}
		// Filling in top side

		i = shift;
		for (j = n - shift - 2; j >= shift + 1; j--) {
			A[i * n + j + 1] = counter;
			counter++;
		}
		shift++;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(dights(n * n)) << A[i * n + j + 1] << " ";
		cout << endl;
	}
	delete[]A;
#endif
}