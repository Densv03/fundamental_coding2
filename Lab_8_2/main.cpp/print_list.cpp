#include "functions.h"
void print_list(List* head){
	system("cls");
	List* temp;
	temp = head;
	int i = 1;
	while (temp != NULL) {
		printf("%d- %s %d %d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
		temp = temp->next;
		i++;
	}
}