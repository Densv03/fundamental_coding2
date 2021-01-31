#include"head.h"
using namespace std;
void all_out() {
	element temp;
	int size = 0;
	string s;
	ifstream file("text.txt");
	while (getline(file, s))
		size++;
	file.close();
	ifstream f("text.txt");
	for (int i = 0; i < size; ++i) {
		f >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
		cout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
	}
	f.close();
}