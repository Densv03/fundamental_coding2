#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<cstring>
#include<Windows.h>
#include<stdio.h>

#define N 30
#define str_sz 15

using namespace std;

struct element{
	char name[str_sz];
	int num, temperature;
	float viscosity;
};

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int temporary;
	struct element el[N];

	for (int i = 0; i < 10; ++i) {
		cout << i + 1 << ". Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";

		cin >> el[i].name >> el[i].num >> el[i].temperature >> el[i].viscosity;

		if (!strcmp(el[i].name, "***")) break;
	}
}