#include<iostream>
#include<Windows.h>
#include<ctime>
#include"functions.h"
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	struct Link* head = nullptr, * m_head = nullptr;
	int data, choice, size;

	while (true) {
		cout << "0. Выйти из программы" << endl;
		cout << "1. Создать список" << endl;
		cout << "2. Напечатать список" << endl;
		cout << "3. Поиск по критерию" << endl;
		cout << "4. Добавление элемента в любое место" << endl;
		cout << "5. Удаление любого элемента" << endl;
		cout << "6. Отсортировать список" << endl;
		cout << "7. Записать новый список в файл" << endl;
		cout << "8. Напечатать список из файла" << endl;
		cout << "Введите номер действия" << endl << "> ";
		int checker;
		cin >> checker;
		while (checker < 0 || checker>8) {
			cout << "Вы ввели некорректное значение. Попробуйте ещё раз: ";
			cin >> checker;
		}
		if (!checker)
			return 0;
		if (checker == 1) {
			size = rand() % 15 + 4;
			for (int i = 0; i < size; ++i)
				adding_to_end(&head, rand() % 15 + 1);
		}
		if (checker == 2) {
			print_list(head);
		}
		if (checker == 3) {

		}
		if (checker == 4) {

		}
		if (checker == 5) {

		}
		if (checker == 6) {

		}
		if (checker == 7) {

		}
		if (checker == 8) {

		}
	}
}