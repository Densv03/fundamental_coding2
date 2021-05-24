#include"functions.h"
#include<iostream>
using namespace std;
void insert_after(struct Link* head, int link_data, int position)
{
	int counter = 0;
	struct Link* prev_link = head;
	while (head != nullptr)
	{
		if (counter == position)
		{
			prev_link = head;
		}
		counter++;
		head = head->next;
	}

	if (prev_link == NULL)
	{
		cout << "the given previous node is required,cannot be NULL"; return;
	}

	struct Link* newLink = new Link;

	newLink->data = link_data;
	newLink->next = prev_link->next;

	prev_link->next = newLink;
}