#include<iostream>
#include<Windows.h>
#include"functions.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите размер массива: ";
	int n;
	cin >> n;
	int* A = new int[n];
	cout << "Хотите ввести элементы с клавиатуры? (Введите 1 если да и 0 в противном случае): ";
	int checker;
	cin >> checker;
	while (checker != 0 && checker != 1) {
		cout << "Введено некорректное значение. Попробуйте ещё раз: ";
		cin >> checker;
	}
	if (checker) {
		cout << "Введите элементы массива" << endl << "> ";
		for (int i = 0; i < n; ++i)
			cin >> A[i];
	}
	else {
		filling(A, n);
		cout << "Элементы массива " << endl << "> ";
		for (int i = 0; i < n; ++i)
			cout << A[i] << " ";
	}
	cout << "Сумма положительных элементов массива" << endl << "> ";
}