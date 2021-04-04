#include"functions.h"
#include<iostream>
using namespace std;
void sort_list(struct Link* head) {
	int temp = head->data;
	while (head != NULL){
		if (temp > head->data)
			temp = head->data;
	}
}