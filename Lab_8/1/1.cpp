#include<iostream>
#include<ctime>
#include<stdio.h>

using namespace std;

short A[100 + 3], n = 100;
bool outputed = false, check = false;

int main() {
	/*                  Randomize                              */
	srand(time(0));
	/*                  Filling in array                       */
	for (int i = 0; i < n; ++i)
		A[i] = rand() % 100 - 50;
	/*                  Ouputting array                        */
	printf("Array: ");
	for (int i = 0; i < n; ++i)
		printf("%d ", A[i]);
	printf("\n");
	/*                   Counting succession                   */
	for (int i = 0; i < n; ++i) {
		if (A[i] > 0 && A[i + 1] < 0 || A[i] < 0 && A[i + 1]>0) {
			if (!outputed) {
				printf("Start element of succession - %d\n", i + 1);
				outputed = true;
			}
			check = true;
		}
		else {
			if (check) {
				check = false;
			}
			if (outputed)
				outputed = false;
		}
	}
}