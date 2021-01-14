#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"head_file.h"
using namespace std;
extern struct element x;
void sorting(element* el, int size) {
	int mn = 0, j = 0, i = 0;
	for (int i = 0; i < size; ++i) {
		mn = i;
		for (j = i + 1; j < size; ++j)
			if (strcmp(el[mn].name, el[j].name) > 0)mn = j;
		if (mn > i) {
			strcpy(x.name, el[i].name);
			x.num = el[i].num;
			x.temperature = el[i].temperature;
			x.viscosity = el[i].viscosity;
			strcpy(el[i].name, el[mn].name);
			el[i].num = el[mn].num;
			el[i].temperature = el[mn].temperature;
			el[i].viscosity = el[mn].viscosity;
			strcpy(el[mn].name, x.name);
			el[mn].num = x.num;
			el[mn].temperature = x.temperature;
			el[mn].viscosity = x.viscosity;
		}
	}
	cout << endl << "Структура отсортирована" << endl << endl;
}