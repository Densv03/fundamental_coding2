#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
int main(){
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << 1;
    FILE* fp;
    int temp, f = 1214134;
    if ((fp = fopen("text.txt", "wb")) == NULL) {
        printf("Error");
        return 1;
    }
    fwrite(&f, sizeof(float), 1, fp);
}