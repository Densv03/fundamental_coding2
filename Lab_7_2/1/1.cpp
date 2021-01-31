#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<fstream>
#include<Windows.h>
#include<cstring>
#include<string>
#include<clocale>

#define str_sz 15
#define n 10

using namespace std;

struct element {
	char name[str_sz];
	int num, temperature;
	float viscosity;
};

string elements[str_sz] = { "Медь","Золото","Вольфрам","Серебро","Ртуть","Алюминий","Свинец","Висмут" };
int nums[str_sz] = { 29,79,74,47,80,13,82,83 };
int temperatures[str_sz] = { 1085,1064,3422,962,-39,660,328,271 };
float viscosities[str_sz] = { 1.2,0.8,4.0,3.2,3.3,2.9,2.1,1.7 };

locale rus("rus_rus.866");

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	element temp;
	srand(time(0));
	while (true) {
		cout << "1. Ввод с экрана и запись в файл" << endl;
		cout << "2. Ввод случайным образом и запись в файл" << endl;
		cout << "3. Добавить запись в начало файла" << endl;
		cout << "4. Добавить запись в конец файла" << endl;
		cout << "5. Печать одной записи из файла по номеру" << endl;
		cout << "6. Печать всех записей из файла" << endl;
		cout << "7. Выход из программы" << endl;
		cout << "8. Очистить консоль" << endl;
		int action;
		cout << "Введите номер действия: ";
		cin >> action;
		while (action > 8 || action < 1) {
			cout << "Введено некорректное значение. Попробуйте ещё раз: ";
			cin >> action;
		}
		if (action == 1) {
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
		else if (action == 2) {
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
		else if (action == 3) {
			string s;
			int size = 0;
			cout << "Введите вещество, атомный номер, температуру (град.С) и вязкость (кг/м*сек)> ";
			cin >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
			ofstream fout("temp-text.txt");
			fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
			fout.close();
			ifstream file("text.txt");
			while (!file.eof()) {
				getline(file, s);
				size++;
			}
			file.close();
			size--;
			int counter = 0;
			for (int i = 1; i <= size; ++i) {
				ifstream file("text.txt");
				for (int j = 0; j < i - 1; ++j)
					getline(file, s);
				file >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
				file.close();
				ofstream fout("temp-text.txt",ios_base::app);
				fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
				fout.close();
			}

		}
		else if (action == 7)
			return 0;
		else if (action == 8)
			system("cls");
	}
}