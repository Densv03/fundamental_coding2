#include"functions.h"
int count_elements(struct Link* head) {
	int counter = 0;
	while (head != nullptr)
	{
		counter++;
		head = head->next;
	}
	return counter;
}