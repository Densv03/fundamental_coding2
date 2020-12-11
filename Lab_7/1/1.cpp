#include<stdio.h>
using namespace std;
float x, y, h;
int main() {
	printf("|   x    |   y  |\n");
	printf("-----------------\n");
	for (short i = 0; i < 5; ++i) {
		// General cycle
		for (float j = 0; j < 4; j += 0.25) {
			// Nested cycle
			if (j >= 0 && j <= 2)
				y = j - 1;
			else if (j > 2 && j <= 3)
				y = j - 3;
			else
				y = -1;
			// Data output
			if (x < 10) {
				if (x >= 0 && y >= 0)
					printf("| %.2f  | %.2f  |\n", x, y);
				else
					printf("| %.2f  | %.2f |\n", x, y);
			}
			else {
				if (x >= 0 && y >= 0)
					printf("| %.2f  | %.2f |\n", x, y);
				else
					printf("| %.2f  | %.2f|\n", x, y);
			}
			printf("-----------------\n");
			x += 0.25;
			if (x > 19)break;
		}
		if (x > 19)break;
	}
	// Building graphic
	x = 0;
	for (short i = 0; i < 5; ++i) {
		for (float j = 0; j < 4; j += 0.25) {
			if (j >= 0 && j <= 2)
				y = j - 1;
			else if (j > 2 && j <= 3)
				y = j - 3;
			else
				y = -1;
			h = (y + 1) * 10;
			if (y - 1 - h * 10 > 0.5) h++;
			// Outputting meaning x
			if (x < 10)
				printf("x = %.2f  |", x);
			else
				printf("x = %.2f |", x);
			// Ouputting graphic
			for (; h > 0; h--) printf(" ");
			printf("*\n", x);
			x += 0.25;
			if (x > 19)break;
		}
		if (x > 19)break;
	}
}