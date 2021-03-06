﻿#include "fun.h"

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice, el;
	List tt;
	bool what = false;
	struct List* head = NULL, * tail = NULL;
	while (true){
		printf("1 - Создать спискок\n");
		printf("2 - Печать списка с начала\n");
		printf("3 - Печать списка с конца\n");
		printf("4 - Поиск элементов по критерию с начала\n");
		printf("5 - Поиск элементов по критерию с конца\n");
		printf("6 - Добавить элемент в любое место\n");
		printf("7 - Удалить элемент\n");
		printf("8 - Отсортировать список\n");
		printf("9 - Записать список в файл \n");
		printf("10 - Создать новый список из файла\n");
		printf("11 - Выйти из программы\n");
		printf(">> ");
		scanf_s("%d", &choice);
		if (choice == 1 || choice == 8) what = true;
		switch (choice) {
		case(1): create_list(head, tail);
			break;
		case(2):
			if (head == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			print_list(head, head, tail); 
			break;
		case(3):
			if(tail == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			print_list(tail, head, tail);
			break;
		case(4):
			if (head == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			else
				search_items_from_begin(head, tail);
			break;
		case(5):
			if (head == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			else
				search_items_from_begin(head, tail);
			break;
		case(6):
			cout << "Введите номер вставляемого элемента -> ";
			scanf_s("%d", &el);
			cout << "Введите значения вставляемого элемента -> ";
			printf("\n  name: ");
			scanf_s("%s", tt.name, 10);
			setbuf(stdin, NULL);
			printf("\n  type: ");
			scanf_s("%d", &tt.num, 10);
			printf("\n  temperature: ");
			scanf_s("%d", &tt.temperature);
			printf("\n  viscosity: ");
			scanf_s("%f", &tt.viscosity);
			add_item(el, tt, head, tail);
			break;
		case(7):
			if (head == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			else {
				cout << "Введите номер удаляемого элемента -> ";
				scanf_s("%d", &el);
				delete_item(el, head, tail);
			}
			break;
		case(8):
			if (head == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			else
				sort_list(head, tail);
			break;
		case(9):
			if (head == NULL) {
				printf("Структуры не существует!!!\n\n");
				break;
			}
			else
				record_list_to_file(head, tail);
			break;
		case(10): 
			head = NULL;
			tail = NULL;
			create_list_from_file(head, tail);
			break;
		case(11):
			printf("Выход\n");
			return 0;
		default:
			system("cls");
			printf("Неверное число\n");
			break;
		}
	}
	free(head);
	return 0;
}