#include<stdio.h>
#include<math.h>
using namespace std;
int main() {
	float a = 3, b = 4, c = 5, p = 0, ans = 0;
	p = (a + b + c) / 2;
	ans = sqrt(p * (p - a) * (p - b) * (p - c));
}