#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<ctime>
#include<Windows.h>
#include"func.h"
#define N 100
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	char* s = new char[N];
	int checker;
	char symbol;
	cout << "Введите строку: " << endl << "> ";
	scanf("%s", s);
	char* pointer;
	pointer = s;
	while (*s != *(s+ size(s) - 1) || size(s)==1) {
		cout << "Введена некорректная строка (Первый и последний символы должны совпадать, строка должна иметь больше одного символа). Повторите ввод:" << endl<<"> ";
		cin >> s;
	}
	cout << "Введите символ который будет удалён: " << endl << "> ";
	cin >> symbol;
	while (symbol != *s) {
		cout << "Введён некорректный символ (Символ должен присутствовать в строке и быть первым и последним элементом). Повторите ввод:" << endl << "> ";
		cin >> symbol;
	}
	char ans[N];
	for (int i = 0; i < N; ++i)
		*(ans + i) = '\0';
	for (int i = 1; i < strlen(s) - 1; ++i)
		*(ans + i - 1) = *(s + i);
	if (!size(ans))
		cout << "Строка пуста";
	else
		for (int i = 0; i < size(ans); ++i)
			cout << *(ans + i);
}