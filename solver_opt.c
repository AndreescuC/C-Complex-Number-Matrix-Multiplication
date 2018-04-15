#include "matrix_utils.h"

double* compute_opt(double* A, double*B, int N)
{
    int i, j, k;
    double* res = malloc(N * N * 2 * sizeof(double));

    double sum_real = 0;
    double sum_img = 0;

    double *orig_A;
    double *A_ptr;
    double *AT_ptr;

    for (i = 0; i < N; i++) {
        orig_A = &A[i * N];
        for (j = 0; j < N; j++) {
            A_ptr = orig_A;
            AT_ptr = &A[j * N];

            sum_real = 0;
            sum_img = 0;
            for (k = 0; k < N && i <= j; k++) {
                //c = multiply(*A_ptr, *(A_ptr + 1), *AT_ptr, *(AT_ptr + 1));
                sum_real += *A_ptr * *AT_ptr - *(A_ptr + 1) * *(AT_ptr + 1);
                sum_img += *A_ptr * *(AT_ptr + 1) + *(A_ptr + 1) * *AT_ptr;

                A_ptr += 2;
                AT_ptr += 2;
            }
            res[2 * (i * N + j)] = sum_real;
            res[2 * (i * N + j) + 1] = sum_img;
        }
    }

    return res;
}

/*
 * Add your optimized implementation here
 */
double* my_solver(int N, double *A) {
    printf("OPT SOLVER\n");
    double *AT = transpose_matrix(A, N);
    double *result = compute_opt(A, AT, N);
    return result;
}
