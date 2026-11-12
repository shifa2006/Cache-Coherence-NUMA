#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int main(int argc, char **argv) {
    size_t mb = argc > 1 ? atol(argv[1]) : 512;
    size_t n = mb << 20;

    char *buf = malloc(n);

    if (buf == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    memset(buf, 1, n);

    long sum = 0;
    double t0 = omp_get_wtime();

    for (int pass = 0; pass < 4; pass++) {
        #pragma omp parallel for reduction(+:sum)
        for (size_t i = 0; i < n; i += 64)
            sum += buf[i];
    }

    printf("Buffer: %zu MB\n", mb);
    printf("Threads: %d\n", omp_get_max_threads());
    printf("Sum: %ld\n", sum);
    printf("Execution Time: %.4f seconds\n",
           omp_get_wtime() - t0);

    free(buf);
    return 0;
}
