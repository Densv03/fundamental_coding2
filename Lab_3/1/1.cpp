#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cmath>
#include<ctime>
#include<iostream>
using namespace std;
int main() {
	float t1, t2, x = 0, y, a = 3, b, c, pi = 3.14, deg_t1, deg_t2, ay;
	srand(time(0));
	a = rand() % 10 + 1;
	x = rand() % 10 + 1;   //
	// t1: a>0 || x>0
	//printf("Enter x for t1: "); --
	//scanf("%f", &x); --
	t1 = (1 / (6 * a)) * log((a * a - a * x + x * x) / ((a + x) * (a + x)) + (1 / (a * sqrt(3))));
	//printf("Enter x for t2: "); --
	//scanf("%f", &y); --
	a = rand() % 10 + 1;
	b = rand() % 10;
	c = rand() % 10 + 1;
	y = rand() % 10;   //
	float ll = 0;
	while (true) {
		if (ll > 0)
			break;
		ay = a * y;
		ll = log(b + (c * (cos(ay * pi / 180))));
		a = rand() % 10 + 1;
		c = rand() % 10 + 1;
		y = rand() % 10;	//
	}
	t2 = (1 / (a * c) * ll);
	// t2: c!=0, a>0, b>c
	printf("t1: %f \nt2: %f\n", t1, t2);
	return 0;
}