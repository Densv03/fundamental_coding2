#include"functions.h"
#include<iostream>
#include <atomic>
void delete_element(struct Link** head_ref, int position) {
	{
		if (*head_ref == NULL)
			return;

		struct Link* temp = *head_ref;

		if (position == 0)
		{
			*head_ref = temp->next;
			free(temp);
			return;
		}

		for (int i = 0; temp != NULL && i < position - 1; i++)
			temp = temp->next;

		if (temp == NULL || temp->next == NULL)
			return;

		struct Link* next = temp->next->next;
		free(temp->next);
		temp->next = next;
	}
}