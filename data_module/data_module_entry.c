#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main(void) {
    int n = 0;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a\n");
        return 0;
    }

    double *data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("n/a\n");
        return 0;
    }


    input(data, n);

    if (normalization(data, n) == 1) {
        output(data, n);
        printf("\n");
    } else {
        printf("n/a\n");
    }

    free(data);

    return 0;
}
