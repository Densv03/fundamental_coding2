#include<stdio.h>
#include<ctime>
#include <stdlib.h>
using namespace std;
int main() {
	int person = 0, coumputer = 0;
	srand(time(0));
	person = rand() % 10 + 1;
	coumputer = rand() % 10 + 1 + 15;
}