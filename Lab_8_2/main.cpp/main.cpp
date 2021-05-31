#include "functions.h"

int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice, el;
	struct List* head = NULL;
	List tt;
	bool what = false;

	while (true) {

		printf("1 - Создание списка\n");
		printf("2 - Печать спика\n");
		printf("3 - Поиск по критерию (осуществить выбор критерия)\n");
		printf("4 - Добавление элемента (в любое заданное место)\n");
		printf("5 - Удаление любого элемента\n");
		printf("6 - Сортировка\n");
		printf("7 - Запись списка в файл \n");
		printf("8 - Создание нового списка из файла \n");
		printf("9 - Выход из программы\n");
		printf("> ");
		scanf_s("%d", &choice);
		if (choice == 1 || choice == 8) what = true;
		switch (choice) {
		case(1): head = create_list();
			break;
		case(2):
			if (head == NULL) {
				printf("There's no structure");
				break;
			}
			print_list(head);
			break;
		case(3):
			if (head == NULL) {
				printf("There's no structure");
				break;
			}
			else
				search_items(head);
			break;
		case(4):
			printf("Enter number of inserted element: ");
			scanf_s("%d", &el);
			printf("Enter inserting meanings: ");
			printf("Name: ");
			scanf_s("%s", tt.name, 10);
			setbuf(stdin, NULL);
			printf("Num: ");
			scanf_s("%d", &tt.num);
			printf("Temperature: ");
			scanf_s("%d", &tt.temperature);
			printf("Viscosity: ");
			scanf_s("%f", &tt.viscosity);
			head = add_item(el, tt, head);
			break;
		case(5):
			if (head == NULL) {
				printf("There's no structure\n");
				break;
			}
			else {
				printf("Enter number of deleted element: ");
				scanf_s("%d", &el);
				head = delete_item(el, head);
			}
			break;
		case(6):
			if (head == NULL) {
				printf("There's no structure\n");
				break;
			}
			else
				head = sort_list(head);
			break;
		case(7):
			if (head == NULL) {
				printf("There's no structure\n");
				break;
			}
			else
				record_list_to_file(head);
			break;
		case(8):
			head = create_list_from_file();
			break;

		case(9):
			return 0;

		default:
			system("cls");
			printf("Incorrect number\n");
			break;
		}
	}
	free(head);
	return 0;
}