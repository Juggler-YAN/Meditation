#include <stdio.h>
#include <math.h>

#define SIZE 3

void transform(double [], double [], int, double (*)(double));
double addOne(double);
double minusOne(double);
void print(double [], int);

int main(void) {
    double a[SIZE] = {1, 2, 3};
    double b[SIZE] = {0, 0, 0};
    print(b, SIZE);
    transform(a, b, SIZE, sin);
    print(b, SIZE);
    transform(a, b, SIZE, cos);
    print(b, SIZE);
    transform(a, b, SIZE, addOne);
    print(b, SIZE);
    transform(a, b, SIZE, minusOne);
    print(b, SIZE);
	return 0;
}

void transform(double a[], double b[], int n, double (*fun)(double)) {
    for (int i = 0; i < n; i++) {
        b[i] = fun(a[i]);
    }
}

double addOne(double a) {
    return a+1.0;
}

double minusOne(double a) {
    return a-1.0;
}

void print(double a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", a[i]);
    }
    printf("\n");
}