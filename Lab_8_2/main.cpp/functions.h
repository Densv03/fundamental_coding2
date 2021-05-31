#pragma once
#ifndef XT
#define XT

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include <time.h>
#include <conio.h>
#include <malloc.h>

using namespace std;

struct List {
	char name[10];
	List* next = NULL;
	int num;
	int temperature;
	float viscosity;
};

struct List* create(void);
void print(List* head);
int search(List* head);
struct List* ADD(int el, List tt, List* head);
struct List* del(int el, List* head);
struct List* sort(List* head);
void addfile(List* head);
struct List* CreateFromFile();

#endif