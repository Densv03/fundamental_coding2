#include<iostream>
#include<Windows.h>
#include<ctime>
#include<utility>
#include<iomanip>
#define sz 100
using namespace std;
pair<int, int>B[sz];
int even;
int func(int *z, int s) {
	const int size = s;
	int counter = 0;
	for (int i = 1; i < size - 1; ++i)
		if (z[i]<z[i - 1] && z[i]>z[i + 1]) {
			counter++;
			cout << "Индекс элемента " << counter << ": " << i + 1 << endl;
		}
	for(int i=0;i<size;++i)
		if (z[i] > 0 && z[i] % 2 == 0) {
			B[even].first = z[i];
			B[even].second = i;
			even++;
		}
	return counter;
}
int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int A[sz], n;
	cout << "Введите размер массива (не более ста): ";
	cin >> n;
	while (n < 1 && n>99) {
		cout << "Вы ввели некорректный размер. Попробуйте ещё раз: ";
		cin >> n;
	}
	cout << "Хотите задать массив с клавиатуры? (1 если да, 0 если нет): ";
	int checker;
	cin >> checker;
	while (checker != 1 && checker != 0) {
		cout << "Вы ввели неправильное значение. Попробуйте ещё раз: ";
		cin >> checker;
	}
	if (checker) {
		cout << "Введите элементы массива" << endl << "> ";
		for (int i = 0; i < n; ++i)
			cin >> A[i];
	}
	else {
		for (int i = 0; i < n; ++i)
			A[i] = rand() % 40 - 20;
		cout << "> ";
		for (int i = 0; i < n; ++i)
			cout << A[i] << " ";
		cout << endl;
	}
	cout << "Всего подходящих чисел: " << func(A, n)<<endl;
	cout << "Второй массив положительных четных чисел и их индексы:" << endl;
	for (int i = 0; i < even; ++i)
		cout << "Число: " << setw(3) << B[i].first << " " << "Индекс: " << setw(2) << B[i].second+1 << endl;
}