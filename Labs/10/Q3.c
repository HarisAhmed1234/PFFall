#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

// Function to fill a 2D array with consecutive prime numbers
void fillWithPrimes(int **matrix, int rows, int cols) {
    int primeCandidate = 2; // Starting from the first prime number

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Find the next prime number
            while (!isPrime(primeCandidate)) {
                primeCandidate++;
            }
            matrix[i][j] = primeCandidate;
            primeCandidate++; // Move to the next number for the next iteration
        }
    }
}

// Function to print a 2D array
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows, numCols;

    // User input for the number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &numCols);

    // Dynamically allocate memory for a 2D array
    int **primeMatrix = (int **)malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++) {
        primeMatrix[i] = (int *)malloc(numCols * sizeof(int));
    }

    // Fill the 2D array with consecutive prime numbers
    fillWithPrimes(primeMatrix, numRows, numCols);

    // Print the 2D array
    printf("2D array of consecutive prime numbers:\n");
    printMatrix(primeMatrix, numRows, numCols);

    // Free dynamically allocated memory
    for (int i = 0; i < numRows; i++) {
        free(primeMatrix[i]);
    }
    free(primeMatrix);

    return 0;
}
