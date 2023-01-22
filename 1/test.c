#include <stdio.h>

double power(double, int);
double powerCore(double, int);

int main(void) {
    double x;
    int n;
    while (scanf("%lf %d", &x, &n) == 2) {
        printf("%f\n", power(x, n));
    }
    return 0;
}

double powerCore(double x, int n) {
    if (n == 1) {
        return x;
    }
    else {
        return x * powerCore(x, n - 1);
    }
}

double power(double x, int n) {
    if (n > 0) {
        return powerCore(x, n);
    }
    else if (n < 0) {
        if (x == 0.0) {
            return 0.0;
        }
        return 1 / powerCore(x, -n);
    }
    else {
        return 1.0;
    }
}