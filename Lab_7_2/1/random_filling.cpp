#include"head.h"
extern string elements[str_sz];
extern int nums[str_sz];
extern int temperatures[str_sz];
extern float viscosities[str_sz];
void random_filling() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	element temp;
	int size = rand() % 7 + 1;
	cout << endl << "Количество элементов: " << size << endl << endl;
	pair<int, bool>mean[str_sz];

	// For random
	for (int i = 0; i < size; ++i) {
		mean[i].first = i;
		mean[i].second = false;
	}
	for (int h = 0; h < size; ++h) {
		int r;
		r = rand() % 8;
		while (mean[r].second)
			r = rand() % 8;
		mean[r].second = true;
		// Random part ended

		char t[str_sz];
		for (int i = 0; i < str_sz; ++i)
			t[i] = '\0';
		// Cleaning array

		string ss;
		ss.clear();
		int str_size = elements[r].size();
		ss = elements[r];
		// Temp string
		for (int i = 0; i < str_size; ++i)
			t[i] = ss[i];
		ss.clear();
		strcpy(temp.name, t);
		temp.num = nums[r];
		temp.temperature = temperatures[r];
		temp.viscosity = viscosities[r];
		if (!h)
			ofstream fout("text.txt");
		ofstream fout("text.txt", ios_base::app);
		fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
		fout.close();
	}
}