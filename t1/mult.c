#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 30000

int main()
{
    double **matrix = malloc(N*sizeof(double *));
    double *vector = malloc(N*sizeof(double));
    double *result = malloc(N*sizeof(double));
    // double s;
    int i, j;
    srand(time(NULL));

    for (i = 0; i< N; i++)
    {
        matrix[i] = malloc(N*sizeof(double));
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 1000;
        }
        vector[i] = rand() % 1000;
        result[i] = 0.0;
    }

    clock_t start, end;
    start = clock();

    for (i = 0; i < N; i++)
    {
        // s = 0.0;
        for (j = 0; j < N; j++)
        {
            // s += matrix[i][j]*vector[j];
            result[i] += matrix[i][j]*vector[j];

        }
        // result[i] = s;
    }

    end = clock();

    printf("Tempo de execucao: %g ms.", (end - start) * 1000.0 / CLOCKS_PER_SEC);

    for (i = 0; i < N; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(vector);
    free(result);

    return 0;
}
