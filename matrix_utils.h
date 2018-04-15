#include "utils.h"

#ifndef MATRIX_UTILS
#define MATRIX_UTILS

typedef struct complex{
    double real;
    double imag;
}complex;

complex multiply(double x, double y, double u, double v);
double* transpose_matrix(double* A, int N);
void display_matrix(double* A, int N);

#endif