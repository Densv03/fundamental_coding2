#include<iostream>
#include<Windows.h>
using namespace std;
#define TYPE 2
//#define N 50
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, counter = 1, k;
	cin >> N;
	cout << "Размер массива равен " << N << '\n';
#if TYPE==1

#else
	int** A = new int* [N];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			A[i][j] = i;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << A[i][j] << " ";
		cout << endl;
	}
#endif

}