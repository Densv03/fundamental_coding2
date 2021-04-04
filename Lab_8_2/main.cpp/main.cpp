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
	int data;
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
		int checker, data;
		cin >> checker;
		while (checker < 0 || checker>8) {
			cout << "Вы ввели некорректное значение. Попробуйте ещё раз: ";
			cin >> checker;
		}
		if (!checker)
			return 0;
		if (checker == 1) {
			head = nullptr;
			cout << "Введите элементы (чтобы закончить ввод, введите -100000): " << endl;
			while (cin >> data) {
				if (data == -100000)
					break;
				add_to_end(&head, data);
			}
		}
		if (checker == 2) {
			print_list(head);
		}
		if (checker == 3) {

		}
		if (checker == 4) {
			int position;
			cout << "Введите элемент, который хотите добавить: ";
			cin >> data;
			cout << "Введите номер элемента, после которого хотите добавить элемент: ";
			cin >> position;
			while (position < 1 || position>count_elements(head)) {
				cout << "Вы ввели некорректное значение. Повторите ввод ещё раз: ";
				cin >> position;
			}
			insert_after(head, data, position - 1);
		}
		if (checker == 5) {
			int position;
			cout << "Введите номер элемента, который нужно удалить: ";
			cin >> position;
			delete_element(&head, position-1);
		}
		if (checker == 6) {

		}
		if (checker == 7) {

		}
		if (checker == 8) {

		}
	}
}