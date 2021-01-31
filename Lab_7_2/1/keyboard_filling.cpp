#include"head.h"
using namespace std;
void keyboard_filling() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	element temp;
	for (int i = 0; i < n; ++i) {
		cout << i + 1 << ". Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";
		cin >> temp.name;
		if (!strcmp(temp.name, "***"))
			break;
		cin >> temp.num >> temp.temperature >> temp.viscosity;

		// For cleaning file when command'll be called more than one time
		if (!i)
			ofstream fout("text.txt");
		ofstream fout("text.txt", ios_base::app);
		fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
		fout.close();
	}
}