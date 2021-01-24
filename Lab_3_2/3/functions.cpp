#include<iostream>
#include<ctime>
using namespace std;
extern int * A, * B, * C, * D, sizes[5];
void filling(int* z, const int size) {
	srand(time(0));
	for (int i = 0; i < size; ++i)
		z[i] = rand() % 50 - 25;
}
void filling_arrs(int* w) {
	const int A_size = sizes[0];
	for (int i = 0; i < A_size; ++i) {
		if (w[i] < 0) {
			B[sizes[1]] = w[i];
			sizes[1]++;
		}
		else if (w[i] > 0) {
			C[sizes[2]] = w[i];
			sizes[2]++;
		}
		else {
			D[sizes[3]] = w[i];
			sizes[3]++;
		}
	}

}
void output(int* z,int x) {
	const int size = x;
	for (int i = 0; i < size; ++i)
		cout << z[i] << " ";
	cout << endl;
}
void refilling(int* y, int* z, int x) {
	const int size = x;
	for (int i = 0; i < size; ++i)
		y[i] = z[i];
}