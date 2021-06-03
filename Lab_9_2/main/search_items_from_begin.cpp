#include"fun.h"
int search_items_from_begin(List* head, List* tail) {
	system("cls");
	int choice;
	List* temp = head;
	int i = 1;
	bool q = true;
	while (true) {
		printf("1 - Поиск по имени\n");
		printf("2 - Поиск по типу\n");
		printf("3 - Поиск по температуре \n");
		printf("4 - Поиск по скорости\n");
		printf("5 - Выход\n");
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
					printf("\n  %d- %s %d %d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\n  Нечего не найдено!!!\n\n");

			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;

		case 2:
			int num1;
			temp = head;
			printf("Num>");
			scanf("%d", &num1);

			while (temp != NULL) {
				if (temp->num == num1) {
					q = false;
					printf("%d- %s %d %d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\n  Нечего не найдено!!!\n\n");

			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;

		case 3:

			int temperature1;
			temp = head;

			printf("\n  temperature>");
			scanf("%d", &temperature1);
			setbuf(stdin, NULL);

			while (temp != NULL) {
				if (temp->temperature == temperature1) {
					q = false;
					printf("%d- %s %d %d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\n  Нечего не найдено!!!\n\n");

			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;

		case 4:

			float viscosity1;
			temp = head;

			printf("Viscosity>");
			scanf("%f", &viscosity1);
			setbuf(stdin, NULL);

			while (temp != NULL) {
				if (temp->viscosity == viscosity1) {
					q = false;
					printf("%d- %s %d %d %.2f\n", i, temp->name, temp->num, temp->temperature, temp->viscosity);
				}
				i++;
				temp = temp->next;
			}
			if (q) printf("\n  Нечего не найдено!!!\n\n");
			q = true;
			temp = NULL;
			i = 1;
			free(temp);
			break;
		case 5:
			printf("\n  Выход\n\n");
			return 0;
			break;
		default:
			printf("\n  Вы ввели не то число!!!\n\n");
			break;
		}
	}
}