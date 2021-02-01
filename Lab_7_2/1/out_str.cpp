#include"head.h"
void out_str(int size) {
	element temp;
	string s;
	ifstream f("text.txt");
	for (int i = 0; i < size - 1; ++i)
		getline(f, s);
	f >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
	f.close();
	cout << endl << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl << endl;
}