#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fin = NULL;
    FILE *ref = NULL;
    FILE *fout = NULL;
    const char *refpath = "/export/asc/tema2/";
    long int fileLen = 0;
    int N;
    double *C;
    double *A;
    int i, j;
    int test_no;
    char filename[100];
    int current_test_err = 0;
    double err = 0.001;
    for (test_no = 1; test_no < 6; test_no++)
    {
        current_test_err = 0 ;
        sprintf(filename, "out%d", test_no);
        fin = fopen(filename, "rb");
        if (fin == NULL)
        {
            perror("fopen error");
            return -1;
        }
        sprintf(filename, "%sout%d", refpath, test_no);
        ref = fopen(filename, "rb");
        if (ref == NULL)
        {
            perror("ref fopen error");
            return -1;
        }
        fseek(fin, 0, SEEK_END);
        fileLen = ftell(fin);
        fseek(fin, 0, SEEK_SET);
        printf("File size is %ld\n", fileLen);
        printf("Matrix rank is %d\n", (int)(sqrt(fileLen / 2 / sizeof(double))));
        sprintf(filename, "%s%d", "diff", test_no);
        fout = fopen(filename, "w");
        if (fout == NULL)
        {
            perror("fopen out error");
            return -1;
        }
        N = (int)sqrt(fileLen / 2 / sizeof(double));
        C = (double *)calloc(2 * N * N, sizeof(double));
        A = (double *)calloc(2 * N * N, sizeof(double));
        fread(C, sizeof(double), 2 * N * N, fin);
        fread(A, sizeof(double), 2 * N * N, ref);
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (fabs(A[2 * ( i * N + j )] - C[2 * (i * N + j)]) > err) {
                    fprintf(fout, "Error at real part of M[%d][%d]\nResult is %lf\nRef is %lf\n", i, j, C[2 * (i * N + j)], A[2 * (i * N + j)]);
                    current_test_err++ ;
                }
                if (fabs(A[2 * ( i * N + j ) + 1] - C[2 * (i * N + j)+1]) > err){
                    fprintf(fout, "Error at imaginary part of M[%d][%d]\nResult is %lf\nRef is %lf\n", i, j, C[2 * (i * N + j)+1], A[2 * (i * N + j)+1]);
                    current_test_err++ ;
                }
            }
        }
        if (current_test_err != 0){
            printf("Test %d failed with %d errors!\n", test_no, current_test_err);
        }
        else
            printf("Test %d passed!\n", test_no);
        fclose(fin);
        fclose(fout);
        fclose(ref);
        free (C);
        free (A);
    }
    printf("Check done\n");
    return 0;
}