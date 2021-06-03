#include"fun.h"
void create_list(struct List*& head, struct List*& tail)
{
	List* p, * pred;
	pred = NULL;
	do {
		p = (List*)malloc(sizeof(List));
		printf("Name: ");
		scanf_s("%s", p->name, 10);
		setbuf(stdin, NULL);
		printf("Num: ");
		scanf_s("%d", &p->num);
		printf("Temperature: ");
		scanf_s("%d", &p->temperature);
		printf("Viscosity: ");
		scanf_s("%f", &p->viscosity);
		p->v1 = pred;
		if (pred != NULL)
			pred->next = p;
		else
			head = p;
		pred = p;
		puts(" Закінчити -'у'");
	} while (_getch() != 'y');
	tail = p;
	tail->next = NULL;
}