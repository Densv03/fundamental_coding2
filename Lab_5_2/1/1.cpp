#include<iostream>
#include<clocale>
#include<iomanip>
#include<Windows.h>
#include"func.h"
using namespace std;
/*
TYPE==1 -> работа с двумерным массивом как с одномерным
TYPE==2 -> работа с двумерным массивом как с двумерным
*/
#define TYPE 2
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, counter = 1, k, shift = 0;
	cout << "Введите размер массива: ";
	cin >> n;
#if TYPE==1
	int* one_ans = new int[n * n + 1];
	one_ans = one_dimensional_arr(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(dights(n * n)) << *(one_ans + i * n + j + 1) << " ";
		cout << endl;
	}
	delete[] one_ans;
#else
	int** two_ans;
	two_ans = new int* [n];
	two_ans = two_dimensional_arr(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << setw(dights(n * n)) <<*(*(two_ans+i)+j)<< " ";
		cout << endl;
	}
	for (int i = 0; i < n; ++i)
		delete[]two_ans[i];
	delete[]two_ans;
#endif
}