#include"head.h"
using namespace std;
void add_to_the_end() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	element temp;
	cout << "������� ��������, ������� �����, ����������� (����.�) � �������� (��/�*���)> ";
	cin >> temp.name >> temp.num >> temp.temperature >> temp.viscosity;
	ofstream fout("text.txt", ios_base::app);
	fout << temp.name << " " << temp.num << " " << temp.temperature << " " << temp.viscosity << endl;
	fout.close();
}