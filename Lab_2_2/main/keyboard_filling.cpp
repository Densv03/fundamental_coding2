#include<iostream>
#include "head_file.h"
using namespace std;
extern int sz;
void keyboard_filling(element* el) {
	int size = 0;
	for (int i = 0; i < 10; ++i) {
		cout << i + 1 << ". Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";

		cin >> el[i].name;
		if (!strcmp(el[i].name, "***")) break;
		cin >> el[i].num >> el[i].temperature >> el[i].viscosity;
		size++;
	}
	sz = size;
}