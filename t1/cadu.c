#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 20000

typedef int data_t;

int main(){

	// Declares variables:
	data_t **matrix, *vector, *result;
	clock_t start, stop;
	int i, j;

	// Allocates space:
	vector = malloc(sizeof(*vector)*N);
	result = malloc(sizeof(*result)*N);
	matrix = malloc(sizeof(*matrix)*N);
	// Runs through N lines:
	for (i = 0; i < N; i++){
		// Allocates matrix rows:
		matrix[i] = malloc(sizeof(**matrix)*N);
		// Fills in matrix values:
		for (j = 0; j < N; j++){
			// Randomizes value:
			matrix[i][j] = rand() % 500;
		}
		// Fills in vector values:
		vector[i] = rand() % 200;
	}

	// Start stopwatch:
	start = clock();

	// Matrix-vector multiplication:
	for (i = 0; i < N; i++){
		// Accumulator variable:
		data_t acc = 0;
		for (j = 0; j < N; j++){
			// Accumulates:
			acc += matrix[i][j] * vector[j];
		}
		// Saves result:
		result[i] = acc;
	}

	// Stop stopwatch:
	stop = clock();

	printf("\nElapsed time: %f sec\n", (stop - start) * 1.0 / CLOCKS_PER_SEC);


}
