#include<iostream>
#include<ctime>
#include"functions.h"
using namespace std;
void adding_to_end(struct Link** head, int link_data) {
	struct Link* newLink = new Link;
	struct Link* last = *head;

	newLink->data = link_data;
	newLink->next = NULL;

	if (*head == NULL) {
		*head = newLink;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newLink;
	return;
}