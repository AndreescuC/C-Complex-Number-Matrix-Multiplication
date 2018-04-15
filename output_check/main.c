#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFF 50000

void log_exit(char *s)
{
    printf("%s\n", s);
    exit(1);
}

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Please provide 2 outputs files to compare: %s out1 out2\n", argv[0]);
        return -1;
    }

    int i = 0;
    double puppet1, puppet2, read1, read2;
    char message[50];

    FILE* fd_out1 = fopen(argv[1], "rb");
    FILE* fd_out2 = fopen(argv[2], "rb");

    while (1) {
        read1 = fread(&puppet1, sizeof(double), 1, fd_out1);
        read2 = fread(&puppet2, sizeof(double), 1, fd_out2);
        if (read1 != 1 || read2 != 1) {
            break;
        }
        printf("Comparing %f with %f\n", puppet1, puppet2);
        if (fabs(puppet1 - puppet2) > 0.01) {
            sprintf(message, "Difference at %d (%f != %f)", i, puppet1, puppet2);
            log_exit(message);
        }
        i++;
    }

    printf("OK\n");

    return 0;
}