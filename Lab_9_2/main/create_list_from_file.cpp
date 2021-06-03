#include "fun.h"
void create_list_from_file(List*& head, List*& tail) {
	List* p, * pred;
	pred = NULL;
	int size = 0, i = 0;
	FILE* file = NULL;
	fopen_s(&file, "Spis1.txt", "r");
	if (file == NULL)
		exit(0);
	char text;
	while (true) {
		text = fgetc(file);
		if (text == '\n')size++;
		else if (text == EOF) break;
	}
	fseek(file, 0, SEEK_SET);
	while (i != size) {
		p = (List*)malloc(sizeof(List));
		fscanf_s(file, "%s", p->name, 10);
		fscanf_s(file, "%d", &p->num);
		fscanf_s(file, "%d", &p->temperature);
		fscanf_s(file, "%f", &p->viscosity);
		i++;
		p->v1 = pred;
		if (pred != NULL)
			pred->next = p;
		else
			head = p;
		pred = p;
		tail = p;
	}
	tail->next = NULL;
	fclose(file);
}