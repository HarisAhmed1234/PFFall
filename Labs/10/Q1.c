#include <stdio.h>
#include <stdlib.h>

// Constants to represent data types
#define INTEGER_TYPE 1
#define DOUBLE_TYPE 2
#define CHAR_TYPE 3

// Function to print the elements of an array
void printArray(void *array, size_t size, size_t elementSize, int dataType) {
    // Cast the void pointer to the appropriate type
    char *ptr = (char *)array; // Enables easy bitwise movement

    // Print each element in the array
    for (size_t i = 0; i < size; ++i) {
        // Use casting and format specifier based on the data type
        switch (dataType) {
            case INTEGER_TYPE:
                printf("%d", *((int *)ptr));
                break;
            case DOUBLE_TYPE:
                printf("%.2f", *((double *)ptr));
                break;
            case CHAR_TYPE:
                printf("%c", *((char *)ptr));
                break;
            // Add more cases for other data types if needed
        }

        // Move the pointer to the next element in the array
        ptr += elementSize;

        // Print a space between elements if not the last element
        if (i < size - 1) {
            printf(" ");
        }
    }

    // Print a newline at the end
    printf("\n");
}

int main() {
    // Example usage with dynamically allocated arrays
    int *integerArray = (int *)malloc(5 * sizeof(int));
    double *doubleArray = (double *)calloc(5, sizeof(double));
    char *charArray = (char *)realloc(NULL, 5 * sizeof(char));

    // Populate the arrays with values
    for (size_t i = 0; i < 5; ++i) {
        integerArray[i] = i + 1;
        doubleArray[i] = (i + 1) * 1.1;
        charArray[i] = 'a' + i;
    }

    // Print integer array
    printf("Printing integerArray: ");
    printArray(integerArray, 5, sizeof(int), INTEGER_TYPE);

    // Print double array
    printf("Printing doubleArray: ");
    printArray(doubleArray, 5, sizeof(double), DOUBLE_TYPE);

    // Print char array
    printf("Printing charArray: ");
    printArray(charArray, 5, sizeof(char), CHAR_TYPE);

    // Free dynamically allocated memory
    free(integerArray);
    free(doubleArray);
    free(charArray);

    return 0;
}

