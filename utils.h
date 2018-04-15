/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 * !!! Do not modify this file !!!
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#ifndef UTILS
#define UTILS

typedef double* (*Solver)(int, double *);

#define get_rand_double(limit) ((((double)rand()) / RAND_MAX) * (2 * limit) - limit)

struct test {
    int seed;
    int N;
    // path to the file where the result matrix will be written
    char output_save_file[100];
};

double* my_solver(int, double *);

int run_test(struct test, Solver, float *);

void free_data(double **);

int generate_data(struct test, double **);

int read_input_file(char *, int *, struct test **);

#endif
