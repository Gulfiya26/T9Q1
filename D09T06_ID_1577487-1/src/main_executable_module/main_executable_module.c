#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"

#ifdef DYNAMIC
#include "../data_module/data_process.h"
#else
#include "../data_module/data_process.h"
#endif

#include "../yet_another_decision_module/decision.h"

void sort(double *data, int n);

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
        sort(data, n);
        output(data, n);
        printf("\n");

        if (make_decision(data, n) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } else {
        printf("n/a\n");
    }

    free(data);
    return 0;
}

void sort(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                double temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
