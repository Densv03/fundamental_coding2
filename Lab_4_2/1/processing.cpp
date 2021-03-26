int k = 0, j = 0;
int* p = new int[100];
int processing(int* z, int* x, int s) {
	const int size = s;
	int counter = 0;
	for (int i = 1; i < size - 1; ++i)
		if (*(z + i) < *(z + i - 1) && *(z + i) > *(z + i + 1))
			counter++;
	for (int i = 0; i < size; ++i)
		if (*(z + i) > 0 && *(z + i) % 2 == 0) {
			*(x + k) = *(z + i);
			k++;
		}
	return counter;
}