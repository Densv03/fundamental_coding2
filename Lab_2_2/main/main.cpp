#include<iostream>
#include<Windows.h>
#include "head_file.h"

#define N 30
#define str_sz 15

struct element el[N], x;
int sz = 0;

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int checker = 0;
	while (true) {
		cout << "Выберите действие: " << endl;
		/*cout << "1. Заполнение структуры случайным образом" << endl;
		cout << "2. Заполнение структуры с клавиатуры" << endl;*/
		cout << "1. Заполнить структуру" << endl;
		cout << "2. Вывести структуру" << endl;
		cout << "3. Отсортировать структуру" << endl;
		cout << "4. Очистить консоль" << endl;
		cout << "Для выхода из программы введите 0" << endl;

		cout << "> ";

		cin >> checker;

		if (checker < 0 || checker>5) {
			cout << "Введено неверное значение. Попробуйте ещё раз: ";
			continue;
		}
		/*else if (checker == 2)
			keyboard_filling(el);*/
		if (checker == 0)
			return 0;
		if (checker == 1)
			struct_filling(el);
		if (checker == 2)
			outputting(el, sz);
		else if (checker == 3)
			sorting(el, sz);
		else if (checker == 4)
			system("cls");
	}
}