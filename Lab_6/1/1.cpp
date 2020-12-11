#include <stdio.h>
#include<Windows.h>
#include <cmath>
int main(void) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n;
    double dbln, sum = 0, term;
    const double eps = 0.00001;
    short k1 = 1;
    for (n = 0; ; n++, k1 = -k1) {
        dbln = n;
        term = k1 * (dbln + 1) / (dbln * dbln + 1);
        if (abs(term) >= eps)
            sum += term;
        else {
            printf("%d\n", n);
            break;
        }

        if (n == 9)
            printf("Sum of 10 succession elements - %10.7lf\n", sum);
    }
    printf("Full sum of succession - %10.7lf\n", sum);
    return 0;
}