#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cmath>
int main() {
	float x = 0, y;
	while (x != 100) {
		printf("Enter x: ");
		scanf("%f", &x);
		printf("Enter y: ");
		scanf("%f", &y);
		if (x > 1 || x < -1 || y > 1 || y < -1) {
			printf("Point isn't in area\n");
			continue;
		}
		else if (abs(x) >= abs(y))printf("Point is in area\n");
		else printf("Point isn't in area\n");
	}
}