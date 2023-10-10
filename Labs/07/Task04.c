#include <stdio.h>

int main() {
    int rows, cols;

    // Ask the user for the number of rows and columns in the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Declare a 2D array
    int matrix[rows][cols];

    // Ask the user to populate the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is symmetric
    int isSymmetric = 1; // Assume the matrix is symmetric by default

 
    if (rows != cols) {
        isSymmetric = 0; // Not symmetric if not square
    } else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != matrix[j][i]) {
                    isSymmetric = 0; // Not symmetric if elements are not equal
                    break; // No need to continue checking
                }
            }
            if (!isSymmetric) {
                break; // No need to continue checking
            }
        }
    }

    // Print the result
    if (isSymmetric) {
        printf("Array is Symmetric:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Array is not Symmetric.\n");
    }

    return 0;
}
