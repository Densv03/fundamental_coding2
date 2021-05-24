#ifndef func
#define func
struct Link {
	int data;
	Link* next;
};
void add_to_end(Link**, int);
void print_list(Link*);
void insert_after(Link*, int, int);
int count_elements(Link*);
void delete_element(Link**, int);
void sort_list(Link*);
#endif
