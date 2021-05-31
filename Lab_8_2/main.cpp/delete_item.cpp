#include "functions.h"
struct List* delete_item(int el, List* head) {
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