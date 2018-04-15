#include "matrix_utils.h"

double* compute_opt(double* A, int N)
{
    int i, j, k;
    complex c;
    double* res = malloc(N * N * 2 * sizeof(double));

    return res;
}

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A) {
    printf("OPT SOLVER\n");
    double *result = compute_opt(A, N);
    return result;
}
