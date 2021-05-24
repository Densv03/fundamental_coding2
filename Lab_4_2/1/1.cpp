#include<iostream>
#include<ctime>
#include<Windows.h>
#include"Head.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int checker, size;
	cout << "Хотите ли Вы ввести размер массива с клаиватуры? Введите 1 если да и 0 в противном случае: ";
	cin >> checker;
	while (checker > 1 || checker < 0) {
		cout << "Вы ввели некорректное значение. Попробуйте ещё раз: ";
		cin >> checker;
	}
	if (checker) {
		cout << "Введите размер массива (не более ста): ";
		cin >> size;
		while (size < 1 || size >= 100) {
			cout << "Вы ввели некорректный размер. Попробуйте ещё раз: ";
			cin >> size;
		}
	}
	else {
		size = rand() % 15 + 1;
		cout << "Размер массива: " << '\n' << "> " << size;
	}
	int* A = new int[size];
	int* B = new int[size];
	filling(A, size);

	cout << "\nЭлементы массива: " << '\n' << "> ";
	for (int i = 0; i < size; ++i)
		cout << *(A + i) << " ";
<<<<<<< HEAD
	cout<<endl << "Количество элементов, которые меньше предыдущего но больше последующего: " << '\n' << "> " << processing(A, B, size);
	extern int k, * positions, j;
	//for (int i = 0; i < j; ++i)
	//	cout << positions[i] << " ";
	if (j) {
		cout << '\n' << "Позиции элементов, которые меньше предыдущего но большу последующего: " << '\n' << "> ";
		for (int i = 0; i < j; ++i)
			cout << *(positions + i) << " ";
		//cout << counter;
	}
	cout << '\n' << "Массив, который состоит из положительных четных элементов:" << '\n' << "> ";
=======
	cout << endl << "Количество элементов, которые меньше предыдущего но больше последующего: " << '\n' << "> " << processing(A, B, size);
	extern int k;
	cout << '\n' << "Массив, который состоит из положительных четных элементов" << '\n' << "> ";
>>>>>>> 32a7ab268208cd3cfadca906f3819d030d3c5087
	for (int i = 0; i < k; ++i)
		cout << *(B + i) << " ";
}