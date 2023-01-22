#include <stdio.h>

#define ROWS 3
#define COLS 5

void getData(double [][COLS], int);
double getAverage(const double [], int);
void getRowAverage(const double [][COLS], int, double []);
double getAllAverage(const double [][COLS], int);
double getMax(const double [][COLS], int);
void printRes(const double [][COLS], int, const double [], double, double);

int main(void) {
    double arr[ROWS][COLS],
           rowAverage[ROWS],
           allAverage,
           max;
    getData(arr, ROWS);
    getRowAverage(arr, ROWS, rowAverage);
    allAverage = getAllAverage(arr, ROWS);
    max = getMax(arr, ROWS);
    printRes(arr, ROWS, rowAverage, allAverage, max);
    return 0;
}

void getData(double arr[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%lf", &arr[i][j]);
        }
    }
}

double getAverage(const double arr[], int len) {
    double total = 0;
    for (int i = 0; i < len; i++) {
        total += arr[i];
    }
    return total / len;
}

void getRowAverage(const double arr1[][COLS], int rows, double arr2[]) {
    for (int i = 0; i < rows; i++) {
        arr2[i] = getAverage(arr1[i], COLS);
    }
}

double getAllAverage(const double arr[][COLS], int rows) {
    double total = 0,
           allAverage;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            total += arr[i][j];
        }
    }
    allAverage = total / (rows * COLS);
    return allAverage;
}

double getMax(const double arr[][COLS], int rows) {
    double max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}

void printRes(const double arr1[][COLS], int rows, const double rowAverage[], double allAverage, double max) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%f ", arr1[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        printf("%f\n", rowAverage[i]);
    }
    printf("%f\n", allAverage);
    printf("%f\n", max);
}