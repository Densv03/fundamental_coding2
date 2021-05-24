using namespace std;
int size(char* z) {
	int size = 0;
	while (*(z + size) != '\0')
		size++;
	return size;
}