#include<iostream>
#include<Windows.h>
#include<ctime>
#include"head.h"
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
			char temp = symbol();
			s += temp;
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
	}
	cout << l;
}