#pragma once
#ifndef fun
#define fun

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "windows.h"
#include <time.h>
#include <conio.h>
#include <malloc.h>
#include <stdio.h>

using namespace std;

struct List {
	char name[10];
	int num;
	int temperature;
	float viscosity;
	List* v1;
	List* next;
};

void create_list(List*& head, List*& tail);
void print_list(List* p, List* head, List* tail);
void delete_item(int el, List* head, List* tail);
int search_items_from_begin(List* head, List* tail);
int search_items_from_end(List* head, List* tail);
void add_item(int el, List tt, List* head, List* tail);
void delete_item(int el, List* head, List *tail);
void sort_list(List* head, List*& tail);
void record_list_to_file(List* head, List* tail);
void create_list_from_file(List*& head,List*& tail);

#endif
