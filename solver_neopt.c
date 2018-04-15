#include "matrix_utils.h"

double* compute_neopt(double* A, int N)
{
    int i, j, k;
    complex c;
    double* res = malloc(N * N * 2 * sizeof(double));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                c = multiply(
                        A[2 * (i * N + k)], A[2 * (i * N + k) + 1],
                        A[2 * (j * N + k)], A[2 * (j * N + k) + 1]
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
    double *result = compute_neopt(A, N);
    return result;
}
