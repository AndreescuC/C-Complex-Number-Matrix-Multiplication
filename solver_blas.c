/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include "CBLAS/include/cblas.h"

/*
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A) {
    printf("BLASS SOLVER\n");

    enum CBLAS_ORDER order = CblasRowMajor;
    enum CBLAS_UPLO uplo = CblasUpper;
    enum CBLAS_TRANSPOSE transpose = CblasTrans;

    double *C = malloc(N * N * 2 * sizeof(double));

    int one = 1;
    int zero = 0;

    cblas_zsyrk(order, uplo, transpose, N, N, &one, A, N, &zero, C, N);

    return C;
}
