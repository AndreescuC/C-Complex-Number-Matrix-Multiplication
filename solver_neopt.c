/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"

typedef struct complex{
    double real;
    double imag;
}complex;

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

double* compute_neopt(double* A, double* B, int N)
{
    int i, j, k;
    complex c;
    double* res = malloc(N * N * 2 * sizeof(double));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c = multiply(
                        A[2 * (i * N + k)], A[2 * (i * N + k) + 1],
                        B[2 * (k * N + j)], B[2 * (k * N + j) + 1]
                );
                res[2 * (i * N + j)] += c.real;
                res[2 * (i * N + j) + 1] += c.imag;
            }
        }
    }
    return res;
}

/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A)
{
    printf("NEOPT SOLVER\n");

    display_matrix(A,N);
    double *AT = transpose_matrix(A, N);
    display_matrix(AT, N);
    double *result = compute_neopt(A, AT, N);
    display_matrix(result, N);
    return result;
}
