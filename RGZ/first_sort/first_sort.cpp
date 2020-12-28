#include<iostream>
#include<ctime>
#include<chrono>
#include<algorithm>
#define K 45
#define N 1000
using namespace std;
int A[N], A_copy[N], B[N], C[N];
double aver_dur, dur_arr[N + 10];
void gnome_sort(int arr[K + 10]) {
	for (int i = 1; i < K; ++i) {
		if (arr[i - 1] > arr[i] && i != 1) {
			swap(arr[i - 1], arr[i]);
			i -= 2;
		}
		else if (arr[i - 1] > arr[i] && i == 1)
			swap(arr[i - 1], arr[i]);
	}
}
int main() {
	srand(time(0));
	for (int i = 0; i < K; ++i) {
		A[i] = rand() % 100;
		A_copy[i] = A[i];
	}
	cout << "Original array: " << endl;
	for (int i = 0; i < K; ++i)
		cout << A[i] << " ";
	for (int j = 0; j < N; ++j) {
		for (int l = 0; l < K; ++l)
			A[l] = A_copy[l];
		/*sort(A, A + K);
		reverse(A, A + K);*/
		auto start = chrono::high_resolution_clock::now();
		gnome_sort(A);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		dur_arr[j] = duration.count();
	}
	cout << endl << "Sorted array:" << endl;
	for (int i = 0; i < K; ++i)
		cout << A[i] << " ";
	cout << endl;
	/*cout << "Duration array: " << endl;
	for (int i = 0; i < N; ++i)
		cout << "Duration " << i+1 << ": " << dur_arr[i] << "s\n";*/
	sort(dur_arr, dur_arr + N);
	for (int i = 100; i < N - 100; ++i)
		aver_dur += dur_arr[i];
	cout << "Average duration: " << aver_dur / (N - 201) << "s";
}