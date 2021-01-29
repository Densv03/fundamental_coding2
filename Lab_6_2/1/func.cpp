#include<iostream>
#include<ctime>
char symbol() {
	srand(time(0));
	int section, el;
	section = rand() % 4 + 1;
	if (section == 1) {
		el = rand() % 10;
		el += 48;
		return (char)el;
	}
	else if (section == 2) {
		el = rand() % 26;
		el += 65;
		return (char)el;
	}
	else {
		el = rand() % 26;
		el += 97;
		return (char)el;
	}
}
