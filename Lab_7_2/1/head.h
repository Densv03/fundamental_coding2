#ifndef head
#define head
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<fstream>
#include<Windows.h>
#include<cstring>
#include<string>
#include<clocale>
#include<stdio.h>
using namespace std;
void keyboard_filling();
void random_filling();
void add_to_begin();
void add_to_the_end();
void out_str(int);
void all_out();
void cleaning();
#define str_sz 15
#define n 10
struct element {
	char name[str_sz];
	int num, temperature;
	float viscosity;
};
#endif // !head