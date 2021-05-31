#include "functions.h"
struct List* create(void){
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
void print(List* head)
{
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
int search(List* head) {
	system("cls");
	int choice;
	List* temp = head;
	char type1[10];
	int tem1, sp1;
	int i = 1;
	bool q = true;
	while (true) {
		printf("1 - Find elements by name\n");
		printf("2 - Find elements by num\n");
		printf("3 - Find elements by temperature\n");
		printf("4 - Find elements by viscosity\n");
		printf("5 - Exit\n");
		printf(">> ");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			char name1[10];
			temp = head;
			printf("\n  name>");
			scanf("%s", name1, 10);
			setbuf(stdin, NULL);
			while (temp != NULL) {
				if (strcmp(temp->name, name1) == 0) {
					q = false;
					printf("%d- %s %d %4d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("There's no elements found\n");
			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;
		case 2:
			int num1;
			temp = head;
			printf("\n  num>");
			scanf("%d", &num1);
			setbuf(stdin, NULL);
			while (temp != NULL) {
				if (temp->num == num1) {
					q = false;
					printf("%d- %s %d %4d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);

				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\nThere's no elements found\n");
			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;
		case 3:
			int temperature1;
			temp = head;
			printf("\n  Temperature> ");
			scanf("%d", &temperature1);
			setbuf(stdin, NULL);
			while (temp != NULL) {
				if (temp->temperature == temperature1) {
					q = false;
					printf("%d- %s %d %4d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\nThere's no elements found\n");
			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;
		case 4:
			int viscosity1;
			temp = head;
			printf("\n Viscosity>");
			scanf("%f", &viscosity1);
			setbuf(stdin, NULL);

			while (temp != NULL) {
				if (temp->viscosity == viscosity1) {
					q = false;
					printf("%d- %s %d %4d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\nThere's no elements found\n");
			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;
		case 5:
			return 0;
			break;
		default:
			printf("You've entered incorrect number");
			break;
		}
	}
}
struct List* ADD(int el, List tt, List* head) {
	List* temp = (List*)malloc(sizeof(List));
	if (el == 1) {
		temp->next = head;
		head = temp;
	}
	else {
		List* temp_pos = head;
		for (int i = 0; i < el - 2; i++)
			temp_pos = temp_pos->next;
		temp->next = temp_pos->next;
		temp_pos->next = temp;
	}
	strcpy(temp->name, tt.name);
	temp->num = tt.num;
	temp->temperature = tt.temperature;
	temp->viscosity = tt.viscosity;
	return head;
}
struct List* del(int el, List* head) {
	List* temp_pos = head;
	if (el == 1) {
		head = head->next;
		free(temp_pos);
	}
	else {
		for (int i = 0; i < el - 2; i++)
			temp_pos = temp_pos->next;
		List* temp = temp_pos->next;
		if (temp->next == NULL) temp_pos->next = NULL;
		else temp_pos->next = temp->next;

		free(temp);
	}
	return head;
}
struct List* sort(List* head) {
	struct List* temp = head;
	int lines = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		lines++;
	}
	List* ptr, * trash, * tmp;
	tmp = (struct List*)malloc(sizeof(struct List));
	for (int n = 0; n < lines; n++) {
		ptr = head;
		while (ptr->next != NULL) {

			temp = ptr->next;
			if (strcmp(ptr->name, temp->name) > 0) {

				trash = temp->next;
				*tmp = *ptr;
				*ptr = *temp;
				free(temp);
				ptr->next = (struct List*)malloc(sizeof(struct List));
				*ptr->next = *tmp;
				ptr->next->next = trash;
			}

			ptr = ptr->next;
		}
	}
	free(tmp);
	return(head);
}
void addfile(List* head) {
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

struct List* CreateFromFile() {

	struct List* head = (struct List*)malloc(sizeof(struct List));
	struct List* tail = head, * temp = head;
	int size = 0, i = 0;
	FILE* file = NULL;
	fopen_s(&file, "data.txt", "r");
	if (file == NULL) {
		exit(0);
	}
	char text;
	while (true) {
		text = fgetc(file);
		if (text == '\n')size++;
		else if (text == EOF) break;
	}
	fseek(file, 0, SEEK_SET);
	while (i != size) {
		fscanf_s(file, "%s", temp->name, 5);
		fscanf_s(file, "%d", &temp->num);
		fscanf_s(file, "%d", &temp->temperature);
		fscanf_s(file, "%f", &temp->viscosity);

		i++;
		tail->next = temp;
		tail = temp;
		temp = (List*)malloc(sizeof(List));
	}
	tail->next = NULL;
	fclose(file);
	return head;
}