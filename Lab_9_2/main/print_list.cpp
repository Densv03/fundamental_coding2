#include"fun.h"
void print_list(List* p, List* head, List* tail) {
	system("cls");
	int i = 1;
	if (p == head)
		while (p != NULL) {
			printf("%d- %s %d  %d  %.2f\n", i, p->name, p->num, p->temperature, p->viscosity);
			i++;
			p = p->next;
		}
	else if (p == tail)
		while (p != NULL) {
			printf("%d- %s %d  %d  %.2f\n", i, p->name, p->num, p->temperature, p->viscosity);
			i++;
			p = p->v1;
		}
	else
		printf("Неправильна адреса");
}