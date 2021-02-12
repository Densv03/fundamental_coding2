#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include "head_file.h"
/*
PRINT_TYPE == 1 -> keyboard filling
PRINT_TYPE == 2 -> random filling
*/
#define PRINT_TYPE 2
//#define DEBUG 1
#define N 30
#define str_sz 15
using namespace std;
extern int sz;
string elements[str_sz] = { "Медь","Золото","Вольфрам","Серебро","Ртуть","Алюминий","Свинец","Висмут" };
int nums[str_sz] = { 29,79,74,47,80,13,82,83 };
int temperatures[str_sz] = { 1085,1064,3422,962,-39,660,328,271 };
float viscosities[str_sz] = { 1.2,0.8,4.0,3.2,3.3,2.9,2.1,1.7 };

void struct_filling(element* el) {
	bool activated = false;
#ifdef DEBUG
	using chrono::system_clock;
	chrono::duration<int, std::ratio<60 * 60 * 24> > one_day(1);
	system_clock::time_point today = system_clock::now();
	time_t tt;
	tt = system_clock::to_time_t(today);
	if (!activated) {
		cout << "today is: " << ctime(&tt) << endl << __FUNCTION__ << endl;
		activated = true;
	}
	cout << __FILE__ << endl << endl;
#endif

#if PRINT_TYPE==1
	int size = 0;
	for (int i = 0; i < 10; ++i) {
		cout << i + 1 << ". Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";

		cin >> el[i].name;
		if (!strcmp(el[i].name, "***")) break;
		cin >> el[i].num >> el[i].temperature >> el[i].viscosity;
		size++;
	}
	sz = size;
#elif PRINT_TYPE==2
	srand(time(0));
	int size = rand() % 7 + 1;
	cout << "Количество элементов: " << size << endl;
	pair<int, bool>mean[str_sz];
	for (int i = 0; i < size; ++i) {
		mean[i].first = i;
		mean[i].second = false;
	}
	for (int h = 0; h < size; ++h) {
		int r;
		r = rand() % 8;
		while (mean[r].second)
			r = rand() % 8;
		mean[r].second = true;
		char temp[str_sz];
		for (int i = 0; i < str_sz; ++i)
			temp[i] = '\0';
		string ss;
		ss.clear();
		int str_size = elements[r].size();
		ss = elements[r];
		for (int i = 0; i < str_size; ++i)
			temp[i] = ss[i];
		ss.clear();
		strcpy(el[h].name, temp);
		el[h].num = nums[r];
		el[h].temperature = temperatures[r];
		el[h].viscosity = viscosities[r];
	}
	cout << "Структура заполнена" << endl;
	sz = size;
#endif
#ifdef DEBUG
	if (activated)
		cout << endl << "DEBUG is defined" << endl << endl;
#endif
}