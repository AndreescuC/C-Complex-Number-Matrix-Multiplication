#include "matrix_utils.h"

complex multiply(double x, double y, double u, double v)
{
    complex res;
    res.real = x * u - y * v;
    res.imag = x * v + y * u;
    return res;
}

double* transpose_matrix(double* A, int N)
{
    int i, j;
    double *AT = malloc(N * N * 2 * sizeof(double));

    for (i = 0; i < N; i++) {
        for(j = 0 ; j < N ; j++) {
            AT[2 * (i * N + j)] = A[2*(j * N + i)];
            AT[2 * (i * N + j) + 1] = A[2*(j * N + i) + 1];
        }
    }
    return AT;
}

void display_matrix(double* A, int N)
{
    int i, j;

    for (i = 0; i < N; i++) {
        for(j = 0 ; j < N ; j++) {
            printf("[%0.1f %0.1fi]  ", A[2 * (i * N + j)], A[2  * (i * N + j) + 1]);
        }
        printf("\n");
    }
    printf("\n");
}