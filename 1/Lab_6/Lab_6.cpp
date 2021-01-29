#include<iostream>
#include<Windows.h>
#include<ctime>
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
	if (checker) {
		cout << "Введите строку: "<<endl<<"> ";
		cin >> s;
	}
	else {
		int sz = rand() % 15 + 1;
		for (int i = 0; i < sz; ++i) {

		}
	}
}