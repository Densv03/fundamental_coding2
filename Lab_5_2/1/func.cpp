int dights(int z) {
	int k = 0;
	while (z > 0) {
		k++;
		z /= 10;
	}
	return k;
}