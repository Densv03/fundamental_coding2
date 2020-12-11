#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cmath>
int main() {
	float a, b, c, desc, x1, x2;
	a = 1;
	b = 1;
	c = -2;
	printf("enter a: ");
	scanf("%f", &a);
	printf("enter b: ");
	scanf("%f", &b);
	printf("enter c: ");
	scanf("%f", &c);
	desc = (b * b) - (4 * a * c);
	if (desc >= 0) {
		x1 = (-b + sqrt(desc)) / (2 * a);
		x2 = (-b - sqrt(desc)) / (2 * a);
		if (desc == 0)
			printf("There's one root of equation: %f", x1);
		else
			printf("There's two roots of equation:\n%f\n%f", x1, x2);
	}
	else
		printf("There isn't any roots of equation");
	return 0;
}