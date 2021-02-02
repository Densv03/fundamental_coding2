#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<cstdio>
#define N 10
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int mas1[N + 1], mas2[N + 1];
	for (int i = 0; i < N; ++i)
		mas1[i] = rand() % 10 + 1;
	FILE* pfile;
	pfile = fopen("f1.txt", "w");
	for (int i = 0; i < N; ++i)
		fprintf(pfile, "%d ", mas1[i]);
	fclose(pfile);
	pfile = fopen("f1.txt", "r");
	for (int i = 0; i < N; ++i)
		fscanf(pfile, "%d", &mas2[i]);
	fclose(pfile);
	pfile = fopen("f2.txt", "w");
	for (int i = 0; i < N; ++i)
		fprintf(pfile, "%d ", mas2[i]);
	fclose(pfile);
	pfile = fopen("f2.txt", "r");
	int x;
	for (int i = 0; i < N; ++i) {
		fscanf(pfile, "%d", &x);
		cout << x << " ";
	}
}