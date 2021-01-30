#include<iostream>
#include<Windows.h>
#include<ctime>
#include<cstring>

char symbol();

char symbol() {
	srand(time(0));
	int section = rand() % 4 + 1;
	if (section == 1) {
		int el = rand() % 10;
		el += 48;
		return (char)el;
	}
	else if (section == 2) {
		int el = rand() % 26;
		el += 65;
		return (char)el;
	}
	else {
		int el = rand() % 26;
		el += 97;
		return (char)el;
	}
}

using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	cout << "Хотите ввести строку с клавиатуры? (Введите 1 если да, иначе - 0): ";
	int checker;
	cin >> checker;
	while (checker != 0 && checker != 1) {
		cout << "Вы ввели некорректное значение. Попробуйте ещё раз: ";
		cin >> checker;
	}
	string s;
	int section, el;
	if (checker) {
		cout << "Введите строку: " << endl << "> ";
		cin >> s;
	}
	else {
		s.clear();
		int sz = rand() % 15 + 1;
		cout << "Размер строки: " << endl << "> " << sz << endl;
		for (int i = 0; i < sz; ++i) {
			int section = rand() % 4 + 1;
			if (section == 1) {
				int el = rand() % 10;
				el += 48;
				s += (char)el;
			}
			else if (section == 2) {
				int el = rand() % 26;
				el += 65;
				s += (char)el;
			}
			else {
				int el = rand() % 26;
				el += 97;
				s += (char)el;
			}
		}
		cout << "Строка: " << endl << "> " << s << endl;
	}
	cout << "Хотите ввести символ который будет искаться в строке? (Введите 1 если да, иначе - 0): ";
	cin >> checker;
	while (checker != 0 && checker != 1) {
		cout << "Вы ввели некорректное значение. Попробуйте ещё раз: ";
		cin >> checker;
	}
	char l;
	if (checker) {
		cout << "Введите символ который будет искаться: " << endl << "> ";
		cin >> l;
	}
	else {
		l = symbol();
		cout << "Символ который будет искаться: " << endl << "> ";
		cout << l;
	}
	int check = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == l) {
			s.erase(i, 1);
			check++;
		}
	if (check)
		for (int i = s.size() - 1; i >= 0; i--)
			if (s[i] == l) {
				s.erase(i, 1);
				check++;
			}
	if (check == 1)
		cout << "Не удалось удалить элемент с конца" << endl;
	cout << "Оставшаяся строка:" << endl << "> " << s;
}