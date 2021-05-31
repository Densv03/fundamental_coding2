#include "functions.h"
struct List* create_list(void) {
	system("cls");
	List* temp, * tail; char c;
	struct List* head = tail = temp = (List*)malloc(sizeof(List));
	printf("Name: ");
	scanf_s("%s", temp->name, 10);
	setbuf(stdin, NULL);
	printf("Num: ");
	scanf_s("%d", &temp->num);
	printf("\Temperature: ");
	scanf_s("%d", &temp->temperature);
	printf("Viscosity: ");
	scanf_s("%f", &temp->viscosity);
	do {
		temp = (List*)malloc(sizeof(List));
		printf("Name: ");
		scanf_s("%s", temp->name, 10);
		setbuf(stdin, NULL);
		printf("Num: ");
		scanf_s("%d", &temp->num, 10);
		printf("Temperature: ");
		scanf_s("%d", &temp->temperature);
		printf("Viscosity: ");
		scanf_s("%f", &temp->viscosity);
		tail->next = temp;
		tail = temp;
		printf("Do you want to end entering structures elements? y/n  ");
		c = _getch();
	} while (c != 'y');
	temp->next = NULL;
	system("cls");
	return head;
}