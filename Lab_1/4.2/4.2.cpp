#include<stdio.h>
using namespace std;
int main() {
	int a = 10, b = 20;
	a *= b;
	b = a / b;
	a /= b;
}