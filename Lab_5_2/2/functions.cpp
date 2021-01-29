#include<iostream>
#include<ctime>
using namespace std;
void filling(int* z,int x){
	const int size = x;
	for (int i = 0; i < size; ++i)
		z[i] = rand() % 50 - 25;
}
int sum(int* z) {
	extern int n;
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (z[i] > 0)ans += z[i];
	return ans;
}
int mult(int* z) {
	extern int n;
	int ans = 1;
	for (int i = 0; i < n; ++i)
		if (z[i] < 0)ans *= z[i];
	return ans;
}