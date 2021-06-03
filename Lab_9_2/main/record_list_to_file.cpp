#include"fun.h"
void record_list_to_file(List* head, List* tail) {
	system("cls");
	List* temp;
	temp = head;
	int i = 1;
	FILE* f;
	fopen_s(&f, "Spis1.txt", "w");
	if (!f) {
		puts("error opening");
		exit(0);
	}
	while (temp != NULL) {
		fprintf_s(f, "%s %d %d %.2f\n", temp->name, temp->num, temp->temperature, temp->viscosity);
		temp = temp->next;
		i++;
	}
	fclose(f);
}