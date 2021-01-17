struct element {
	char name[15];
	int num, temperature;
	float viscosity;
};

#ifndef head_file
#define head_file
	//void keyboard_filling(element *el);
	void struct_filling(element* el);
	void outputting(element* el, int size);
	void sorting(element* el, int size);
#endif