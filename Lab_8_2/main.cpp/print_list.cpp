#include"functions.h"
#include<iostream>
using namespace std;
void print_list(struct Link* head) {
	while (!head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}