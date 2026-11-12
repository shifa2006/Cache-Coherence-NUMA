#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ITERATIONS 10000000

struct Adjacent {
    long long counter[2];
};

struct Padded {
    long long counter[2][8];
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./false_sharing adjacent|padded\n");
        return 1;
    }

    double start, end;

    if (argv[1][0] == 'a') {
        struct Adjacent data = {{0, 0}};

        start = omp_get_wtime();

        #pragma omp parallel num_threads(2)
        {
            int id = omp_get_thread_num();
            for (long long i = 0; i < ITERATIONS; i++)
                data.counter[id]++;
        }

        end = omp_get_wtime();
        printf("Adjacent counters\n");
        printf("Counter 1: %lld\nCounter 2: %lld\n", data.counter[0], data.counter[1]);
    } else {
        struct Padded data = {0};

        start = omp_get_wtime();

        #pragma omp parallel num_threads(2)
        {
            int id = omp_get_thread_num();
            for (long long i = 0; i < ITERATIONS; i++)
                data.counter[id][0]++;
        }

        end = omp_get_wtime();
        printf("Padded counters\n");
        printf("Counter 1: %lld\nCounter 2: %lld\n", data.counter[0][0], data.counter[1][0]);
    }

    printf("Execution Time: %f seconds\n", end - start);
    return 0;
}
