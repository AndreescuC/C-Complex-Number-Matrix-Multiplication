CC=gcc
FC = gfortran
LOADER = $(FC)
CFLAGS=-Wall -Werror -O0
OTHER_C_FLAGS=-Wall -Werror


all: tema2_blas tema2_neopt tema2_opt_m tema2_opt_f build_checker

plot: plot_gcc

tema2_neopt: solver_neopt.c main.c matrix_utils.h matrix_utils.c
	$(CC) $(CFLAGS) $^ $(LIBDIRS) $(LIBS) -o $@

tema2_blas: solver_blas.c main.c matrix_utils.c matrix_utils.h
	$(CC) -L/usr/lib64/atlas/ $(CFLAGS) -o $@ -lsatlas $^

tema2_opt_f: solver_neopt.c main.c matrix_utils.h matrix_utils.c
	$(CC) $(OTHER_C_FLAGS) $^ $(LIBDIRS) $(LIBS) -o $@

tema2_opt_m: solver_opt.c main.c matrix_utils.h matrix_utils.c
	$(CC) $(CFLAGS) $^ $(LIBDIRS) $(LIBS) -o $@

build_checker: output_check/main.c
	$(CC) $(CFLAGS) $^ -o ocheck

plot_gcc: gcc_out_data
	gnuplot -persistent -e "set xlabel 'Matrix dimension'; set ylabel 'Time (sec)';
    plot 'gcc_out_data' using 1:2 with lines title 'blas', 'gcc_out_data' using 1:3 with lines title 'opt_m', plot 'gcc_out_data' using 1:4 with lines title opt_f', 'gcc_out_data' using 1:5 with lines title 'neopt'"

clean:
	rm -rf tema2_blas tema2_neopt tema2_opt_m tema2_opt_f ocheck




