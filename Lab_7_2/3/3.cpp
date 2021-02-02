#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<ctime>
#define M 15
using namespace std;
int main() {
	srand(time(0));
	FILE* pfile;
	int mas1[M], x, sum = 0, mas2[M];
	int N = rand() % 15 + 1;
	cout << "Array's sum: " << endl << "> " << N << endl;
	for (int i = 0; i < N; ++i)
		mas1[i] = rand() % 15;
	pfile = fopen("f1.txt", "w");
	for (int i = 0; i < N; ++i)
		fprintf(pfile, "%d ", mas1[i]);
	fclose(pfile);
	pfile = fopen("f1.txt", "r");
	for (int i = 0; i < N; ++i) {
		fscanf(pfile, "%d", &x);
		mas2[i] = x;
	}
	/*for (int i = 0; i < N; ++i)
		cout << mas2[i] << " ";
	cout << endl;*/
	for (int i = 0; i < N; ++i) {
		x = mas2[i];
		if (x % 2 == 0) {
			sum += x;
			//cout << x << " " << sum << endl;
		}
	}
	cout << "Array:" << endl << "> ";
	for (int i = 0; i < N; ++i)
		cout << mas1[i] << " ";
	cout << endl << "Even's sum: "<<endl<<"> " << sum;
}