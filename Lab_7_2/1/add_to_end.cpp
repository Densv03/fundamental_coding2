#include"head.h"
using namespace std;
void add_to_the_end() {
	element temp;
	cout << "Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";
	cin >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
	ofstream fout("text.txt", ios_base::app);
	fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
	fout.close();
}