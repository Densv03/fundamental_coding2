#include"head.h"
using namespace std;
void add_to_begin() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	element temp;
	string s;
	int size = 0;
	cout << "Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";
	cin >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;

	// Enter meaning to temp .txt file
	ofstream fout("temp-text.txt");
	fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
	fout.close();

	// Size counting
	ifstream file("text.txt");
	if (!file.is_open())
		cout << "Не удалось открыть файл text.txt";
	while (!file.eof()) {
		getline(file, s);
		size++;
	}
	file.close();
	size--;
	int counter = 0;
	for (int i = 1; i <= size; ++i) {
		ifstream file("text.txt");

		// Counting place for pointer to read inf
		for (int j = 0; j < i - 1; ++j)
			getline(file, s);
		file >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
		file.close();
		ofstream fout("temp-text.txt", ios_base::app);
		fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
		fout.close();
	}
	size++;

	// Copying temp-text.txt to text.txt
	for (int i = 1; i <= size; ++i) {
		ifstream file("temp-text.txt");
		for (int j = 0; j < i - 1; ++j)
			getline(file, s);
		file >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
		file.close();
		if (i == 1)
			ofstream fout("text.txt");
		ofstream fout("text.txt", ios_base::app);
		fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
	}
	remove("temp-text.txt");
}