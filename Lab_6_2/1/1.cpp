#include<string>
#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	string s;
	int checker, size;
	char symbol;
	cout << "Введите строку: " << endl << "> ";
	cin >> s;
	while (s[0] != s[s.size() - 1] || s.size()==1) {
		cout << "Введена некорректная строка (Первый и последний символы должны совпадать, строка должна иметь больше одного символа). Повторите ввод:" << endl<<"> ";
		cin >> s;
	}
	cout << "Введите символ который будет удалён: " << endl << "> ";
	cin >> symbol;
	while (symbol != s[0]) {
		cout << "Введён некорректный символ (Символ должен присутствовать в строке). Повторите ввод:" << endl << "> ";
		cin >> symbol;
	}
	s.erase(0, 1);
	s.erase(s.size() - 1, 1);
	if (s.empty())
		cout << "Строка пуста";
	else
		cout << s;
}