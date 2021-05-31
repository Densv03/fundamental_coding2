#include "functions.h"
struct List* sort_list(List* head) {
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