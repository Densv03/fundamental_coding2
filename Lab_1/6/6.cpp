#include<stdio.h>
using namespace std;
int main() {
	int time = 0, time1 = 0;
	time = 10 * 366 * 24 * 60 * 60; // no overflow
	time1 = 100 * 366 * 24 * 60 * 60; // overflow
}