#include<iostream>
#include<ctime>
#include<Windows.h>
#include"func.h"
#define N 100
using namespace std;
int a[N], * A = a, b[N], * B = b, c[N], * C = c, d[N], * D = d, sizes[5];
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	const int size = rand() % 10 + 1;
	cout << "Размер массива: " << size << endl;
	filling(A, size);
	sizes[0] = size;
	for (int i = 0; i < size; ++i)
		cout << A[i] << " ";
	cout << '\n';
	filling_arrs(A);
	cout << "Массив В" << endl << "> ";
	output(B, sizes[1]);
	cout << "Массив C" << endl << "> ";
	output(C, sizes[2]);
	cout << "Массив D" << endl << "> ";
	output(D, sizes[3]);
	cout << "Массив А с нулевыми элементами: " << '\n';
	refilling(A, D, sizes[3]);
	output(A, sizes[3]);
	cout << "Массив А с отрицательными элементами: " << '\n';
	refilling(A, B, sizes[1]);
	output(A, sizes[1]);
	cout << "Массив А с положительными элементами: " << '\n';
	refilling(A, C, sizes[2]);
	output(A, sizes[2]);
}