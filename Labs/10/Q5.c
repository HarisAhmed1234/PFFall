#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to multiply each element by 3 and then divide it by 2
void modifyArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            array[i][j] = (array[i][j] * 3) / 2;
        }
    }
}

// Function to create a 2D array with multiple malloc calls
int** createArrayMultiMalloc(int rows, int cols) {
    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }
    return array;
}

// Function to create a 2D array with only 2 malloc calls
int** createArraySingleMalloc(int rows, int cols) {
    int** array = (int**)malloc(rows * sizeof(int*));
    array[0] = (int*)malloc(rows * cols * sizeof(int));
    for (int i = 1; i < rows; ++i) {
        array[i] = array[0] + i * cols;
    }
    return array;
}

// Function to free a 2D array created with multiple malloc calls
void freeArrayMultiMalloc(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(array[i]);
    }
    free(array);
}

// Function to free a 2D array created with only 2 malloc calls
void freeArraySingleMalloc(int** array) {
    free(array[0]);
    free(array);
}

int main() {
    // Define array sizes
    int arraySizes[][2] = {{100, 100}, {500, 500}, {800, 800}};
    
    for (int sizeIndex = 0; sizeIndex < sizeof(arraySizes) / sizeof(arraySizes[0]); ++sizeIndex) {
        int rows = arraySizes[sizeIndex][0];
        int cols = arraySizes[sizeIndex][1];

        // Timing for array created with multiple malloc calls
        clock_t startTimeMultiMalloc = clock();
        int** arrayMultiMalloc = createArrayMultiMalloc(rows, cols);
        modifyArray(arrayMultiMalloc, rows, cols);
        freeArrayMultiMalloc(arrayMultiMalloc, rows);
        clock_t endTimeMultiMalloc = clock();
        printf("Array Size %dx%d (Multi Malloc): %f seconds\n", rows, cols, (double)(endTimeMultiMalloc - startTimeMultiMalloc) / CLOCKS_PER_SEC);

        // Timing for array created with only 2 malloc calls
        clock_t startTimeSingleMalloc = clock();
        int** arraySingleMalloc = createArraySingleMalloc(rows, cols);
        modifyArray(arraySingleMalloc, rows, cols);
        freeArraySingleMalloc(arraySingleMalloc);
        clock_t endTimeSingleMalloc = clock();
        printf("Array Size %dx%d (Single Malloc): %f seconds\n", rows, cols, (double)(endTimeSingleMalloc - startTimeSingleMalloc) / CLOCKS_PER_SEC);
        
        printf("\n");
    }

    return 0;
}
