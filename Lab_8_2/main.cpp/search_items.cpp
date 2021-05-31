#include "functions.h"
int search_items(List* head) {
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