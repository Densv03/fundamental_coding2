int dights(int z) {
	int k = 0;
	while (z > 0) {
		k++;
		z /= 10;
	}
	return k;
}
int* one_dimensional_arr(int size) {
	int n = size, counter = 1, shift = 0;
	int* A = new int[n * n + 1];
	if (n % 2)
		*(A + ((n / 2) * n) + ((n / 2) + 1)) = n * n;
	for (int h = 0; h < n / 2; ++h) {
		// Filling in left side

		for (int i = shift; i < n - shift; ++i) {
			int j = shift;
			*(A + i * n + j + 1) = counter;
			counter++;
		}
		// Filling in bottom

		int i = n - shift - 1;
		for (int j = shift + 1; j < n - shift; ++j) {
			*(A + i * n + j + 1) = counter;
			counter++;
		}
		// Filling in right side

		int j = n - shift - 1;
		for (int i = n - shift - 2; i >= shift; --i) {
			*(A + i * n + j + 1) = counter;
			counter++;
		}
		// Filling in top side

		i = shift;
		for (j = n - shift - 2; j >= shift + 1; j--) {
			*(A + i * n + j + 1) = counter;
			counter++;
		}
		shift++;
	}
	return A;
}
int** two_dimensional_arr(int size) {
	int** A;
	int n = size, counter = 1, shift = 0;
	A = new int* [n];
	for (int i = 0; i < n; ++i)
		*(A + i) = new int[n];
	if (n % 2)
		*(*(A + n / 2) + n / 2) = n * n;
	// General cycle
	for (int h = 0; h < n / 2; ++h) {
		// Filling in left side

		for (int i = shift; i < n - shift; ++i) {
			int j = shift;
			*(*(A + i) + j) = counter;
			counter++;
		}
		// Filling in bottom

		int i = n - shift - 1;
		for (int j = shift + 1; j < n - shift; ++j) {
			*(*(A + i) + j) = counter;
			counter++;
		}
		// Filling in right side

		int j = n - shift - 1;
		for (int i = n - shift - 2; i >= shift; --i) {
			*(*(A + i) + j) = counter;
			counter++;
		}
		// Filling in top side

		i = shift;
		for (j = n - shift - 2; j >= shift + 1; j--) {
			*(*(A + i) + j) = counter;
			counter++;
		}
		shift++;
	}
	return A;
}