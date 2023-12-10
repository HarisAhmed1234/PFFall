# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

void student(char name[]);
int submatrix(int row, int col, int **arr1, int **arr2);

int main(int argc, char const *argv[]){
      if(argc<2){
        printf("Enter the filename as command line argument!");
        return 1;
    }

    FILE *_file = fopen(argv[1],"r");
    if(_file == NULL){
        printf("Error in opening file\n");
        return 1;
    }

    char name[8];
    printf("Input student ID: ");
    fgets(name, 8, stdin);

    // Ask the user for the number of rows and columns.
    int row, col;
    printf("Input the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    // Dynamically allocate memory for a 2D array (matrix) using malloc.
    int **arr1 = (int **)malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        arr1[i] = (int *)malloc(col * sizeof(int));
    }

    // Read values from the file into the matrix.
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            fscanf(_file, "%d", &arr1[i][j]);
        }
    }

    // Dynamically allocate memory for a new 2D array (matrix) using calloc
    int **arr2 = (int **)calloc(row / 2, sizeof(int *));
    for(int i = 0; i < row / 2; i++){
        arr2[i] = (int *)calloc(col / 2, sizeof(int));
    }

    // Call the subset function to find the maximum values in 2x2 submatrices.
    submatrix(row, col, arr1, arr2);

    // Print the information.
    student(name);

    // Print the updated contents of the new array.
    for (int i = 0; i < row / 2; i++){
        for (int j = 0; j < col / 2; j++)
            printf("%d ", arr2[i][j]);
        printf("\n");
    }

    // Close the file.
    fclose(_file);

    // Deallocate the memory used by the arrays.
    for (int i = 0; i < row; i++){
        free(arr1[i]);
    }
    free(arr1);

    for (int i = 0; i < row / 2; i++){
        free(arr2[i]);
    }
    free(arr2);

    return 0; // Indicates successful completion of the program.
}

int submatrix(int row, int col, int **arr1, int **arr2){
    // Loop through the original matrix with steps of 2 for both rows and columns.
    int newrow = 0, newcol = 0;
    for (int i = 0; i < row; i += 2){
        newcol = 0;
        for (int j = 0; j < col; j += 2){
            // Find the largest value in the 2x2 submatrix.
            int largest = arr1[i][j];
            for (int a = i; a < i + 2; a++){
                for (int b = j; b < j + 2; b++){
                    if (arr1[a][b] > largest)
                        largest = arr1[a][b];
                }
            }
            // Store the largest value in the new array.
            arr2[newrow][newcol] = largest;
            newcol++;
        }
        newrow++;
    }
    return 1;
}

void student(char name[]){
    printf("Name: Haris Ahmed\nStudent Id: ");
    for (int i = 3; i < strlen(name); i++)
        printf("%c", name[i]);
    printf("\n");
}
