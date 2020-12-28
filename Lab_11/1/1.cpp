#include<iostream>
#include<ctime>
#define N 30
using namespace std;
int A[N];
int mn = INT_MAX;
int minimum(const int, int, int);
int minimum(const int size, int k, int z[]) {
	while (k != size) {
		mn = (z[k] < mn) ? z[k] : mn;
		//cout << mn << endl;
		return minimum(size, k + 1, A);
	}
	return mn;
}
int main() {
	srand(time(0));
	const int size = rand() % 10 + 1;
	cout << "Array size> " << size << endl;
	cout << "Do you want to enter array by keyboard? (Enter 1 or 0 respectively): ";
	int checker;
	cin >> checker;
	while (checker != 0 && checker != 1) {
		cout << "You've entered incorrect value. Try again: ";
		cin >> checker;
	}
	if (checker == 1) {
		cout << "Enter " << size << " elements: " << endl;
		for (int i = 0; i < size; ++i)
			cin >> A[i];
	}
	else {
		for (int i = 0; i < size; ++i)
			A[i] = rand() % 10;
		cout << "Array> ";
		for (int i = 0; i < size; ++i)
			cout << A[i] << " ";
		cout << endl;
	}
	cout << "Do you want to enter start point for searching mininum value? (Enter 1 or 0 respectively): ";
	cin >> checker;
	while (checker != 1 && checker != 0) {
		cout << "You've entered incorrect value. Try again: ";
		cin >> checker;
	}
	int k;
	if (checker == 1) {
		cout << "Enter value: ";
		cin >> k;
	}
	else {
		k = rand() % 10 + 1;
		while (k > size - 1)
			k = rand() % 10 + 1;
		cout << "Start point> " << k + 1 << endl;
	}
	cout << minimum(size, k, A);
}