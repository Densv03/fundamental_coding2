#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#define N 20
using namespace std;
int main() {
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FILE* fp;
    int  f;

    // Filling in text.txt
    // Looking for errors
    if ((fp = fopen("text.txt", "wb")) == NULL) {
        printf("Error");
        return 1;
    }
    //
    for (int i = 0; i < 20; ++i) {
        f = rand() % 15 + 1;
        fwrite(&f, sizeof(int), 1, fp);
    }
    fclose(fp);
    //

    if ((fp = fopen("text.txt", "r")) == NULL) {
        printf("Error");
        return 1;
    }
    int t, A[N + 5];

    // Checking file's elements
    fread(A, sizeof A, 1, fp);
    for (int i = 0; i < N; ++i)
        cout << A[i] << " ";
    cout << endl;

    // Finding minimum element 
    int u = 0, mn = INT_MAX, comp_temp, pos;
    for (int i = 0; i < N; ++i) {
        fseek(fp, u, SEEK_SET);
        comp_temp = getc(fp);
        if (comp_temp < mn)
            mn = comp_temp;
        u += 4;
    }
    

    // Writing places of min elements
    u = 0;
    int ff = 999, min_arr[N + 5] = { 0 }, min_counter = 0;
    for (int i = 0; i < N; ++i) {
        fseek(fp, u, SEEK_SET);
        comp_temp = getc(fp);
        if (comp_temp == mn) {
            min_arr[min_counter] = u;
            min_counter++;
        }
        u += 4;
    }

    // Counting sum 2,5,9 elements
    int cc = 4, sum = 0;
    fseek(fp, cc * 1, SEEK_SET);
    int temp;
    temp = getc(fp);
    sum += temp;
    fseek(fp, cc * 4, SEEK_SET);
    temp = getc(fp);
    sum += temp;
    fseek(fp, cc * 8, SEEK_SET);
    temp = getc(fp);
    sum += temp;
    cout << "Сумма 2, 5 и 9 элемента: " << sum << endl;
    fclose(fp);
    //

    int i = 1;
    //cout << min_arr[0] << " ";
    /*while (min_arr[i] != 0) {
        cout << min_arr[i] << " ";
        i++;
    }*/
    u = min_arr[0];

    /*fseek(fp, u+4, SEEK_SET);
    int x = getc(fp);
    cout << endl << x;*/
    fclose(fp);
    fp = fopen("text.txt", "r");
    /*cout << min_arr[0];*/
    fseek(fp, min_arr[0], SEEK_SET);
    //cout << endl << getc(fp);
    fclose(fp);
    fp = fopen("text.txt", "w");
    int h = 999;
    fseek(fp, min_arr[0], SEEK_SET);
    fwrite(&h, sizeof(int), 1, fp);
    fclose(fp);


    fp = fopen("text.txt", "r");
    fseek(fp, 0, SEEK_SET);
    fread(A, sizeof A, 1, fp);
    for (int i = 0; i < N; ++i)
        cout << A[i] << " ";
    fclose(fp);
}