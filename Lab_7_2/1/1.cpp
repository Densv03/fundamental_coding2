#include"head.h"

using namespace std;

string elements[str_sz] = { "Медь","Золото","Вольфрам","Серебро","Ртуть","Алюминий","Свинец","Висмут" };
int nums[str_sz] = { 29,79,74,47,80,13,82,83 };
int temperatures[str_sz] = { 1085,1064,3422,962,-39,660,328,271 };
float viscosities[str_sz] = { 1.2,0.8,4.0,3.2,3.3,2.9,2.1,1.7 };

locale rus("rus_rus.866");

int main() {
	element temp;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
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
		if (action == 1)
			keyboard_filling();
		else if (action == 2)
			random_filling();
		else if (action == 3)
			add_to_begin();
		else if (action == 4)
		add_to_the_end();
		else if (action == 5) {
			cout << "Введите номер строки которую хотите получить: ";
			int sz = 0, size;
			string s;
			cin >> size;
			ifstream file("text.txt");
			while (getline(file, s))
				sz++;
			while (size > sz || size < 0) {
				cout << "Введено некорректное значение. Попробуйте ещё раз. (количество строк в файле - " << sz << "): ";
				cin >> size;
			}
			file.close();
			out_str(size);
		}
		else if (action == 6) {
			all_out();
		}
		else if (action == 7)
			return 0;
		else if (action == 8)
			cleaning();
	}
}