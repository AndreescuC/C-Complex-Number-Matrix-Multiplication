CC=gcc
FC = gfortran
LOADER = $(FC)
CFLAGS=-Wall -Werror -O0
OTHER_C_FLAGS=-Wall -Werror


all: tema2_neopt tema2_blas

tema2_neopt: solver_neopt.c main.c matrix_utils.h matrix_utils.c
	$(CC) $(CFLAGS) $^ $(LIBDIRS) $(LIBS) -o $@

tema2_blas: solver_blas.c main.c
	$(CC) -L/usr/lib64/atlas/ $(CFLAGS) -lsatlas $^

clean:
	rm -rf tema2_blas tema2_neopt
