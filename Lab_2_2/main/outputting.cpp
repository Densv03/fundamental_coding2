#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <stdio.h>
#include "head_file.h"
#define DEBUG 1
using namespace std;
void outputting(element* el, int size) {
	bool activated = false;
#ifdef DEBUG
	using chrono::system_clock;
	chrono::duration<int, std::ratio<60 * 60 * 24> > one_day(1);
	system_clock::time_point today = system_clock::now();
	time_t tt;
	tt = system_clock::to_time_t(today);
	if (!activated) {
		cout << "today is: " << ctime(&tt) << __FUNCTION__ << endl;
		activated = true;
	}
#endif // DEBUG

	printf("-------------------------------------------------------------------------------\n");
	printf("| Вязкость металлов в жидком состоянии                                        |\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("| Вещество  | Атомный номер   | Температура (град.С)  | Вязкость (кг/м*сек)   |\n");

	for (int i = 0; i < size; ++i) {
		printf("|-----------|-----------------|-----------------------|-----------------------|\n");
		printf("| %9s | %-16d| %-22d| %-22.2f|\n", el[i].name, el[i].num, el[i].temperature, el[i].viscosity);
	}
	printf("|-----------------------------------------------------------------------------|\n");
	printf("| Примечание: данные даны для температуры плавления                           |\n");
	printf("-------------------------------------------------------------------------------\n\n");
#ifdef DEBUG
	if (activated)
		cout << "DEBUG is defined" << endl << endl;
#endif // DEBUG
}