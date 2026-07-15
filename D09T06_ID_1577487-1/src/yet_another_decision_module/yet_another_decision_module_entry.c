#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

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

    if (make_decision(data, n) == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    free(data);

    return 0;
}
