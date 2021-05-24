#include<iostream>
#include<ctime>
void filling(int* z, int x) {
	srand(time(0));
	const int size = x;
	for (int i = 0; i < size; ++i)
		*(z + i) = rand() % 50 - 25;
}