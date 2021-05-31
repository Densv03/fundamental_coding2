#include "functions.h"
void record_list_to_file(List* head) {
	system("cls");
	List* temp;
	temp = head;
	int i = 1;
	FILE* f;
	fopen_s(&f, "data.txt", "w");
	if (!f) {
		puts("error opening");
		exit(0);
	}
	while (temp != NULL)
	{
		fprintf_s(f, "%s %d %d %.2f\n", temp->name, temp->num, temp->temperature, temp->viscosity);
		temp = temp->next;
		i++;
	}
	fclose(f);
}