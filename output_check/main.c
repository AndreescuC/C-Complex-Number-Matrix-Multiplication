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

    double out1[BUFF], out2[BUFF];
    char message[50];

    FILE* fd_out1 = fopen(argv[1], "rb");
    FILE* fd_out2 = fopen(argv[1], "rb");

    size_t out_size1 = fread(out1, BUFF, 1, fd_out1);
    size_t out_size2 = fread(out2, BUFF, 1, fd_out2);

    if (out_size1 != out_size2) {
        sprintf(message, "Different bytes nr read(%d != %d)", (int)out_size1, (int)out_size2);
        log_exit(message);
    }
    if (BUFF < out_size1) {
        sprintf(message, "Read more than 50000 from out1(%d)", (int)out_size1);
        log_exit(message);
    }
    if (BUFF < out_size2) {
        sprintf(message, "Read more than 50000 from out2(%d)", (int)out_size2);
        log_exit(message);
    }

    int i, size = (int)out_size1;
    for (i=0; i<size; i++) {
        if (fabs(out1[i] - out2[i]) > 0.01) {
            sprintf(message, "Difference at %d/%d(%f != %f)", i, size, out1[i], out2[i]);
            log_exit(message);
        }
    }
    printf("OK\n");
}