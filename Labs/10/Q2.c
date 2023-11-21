#include <stdio.h>

// Generic function to swap values of two variables using XOR bitwise operator
void swap(void *ptr1, void *ptr2, size_t size) {
    // Pointers to bytes, allowing manipulation at the byte level
    unsigned char *bytePtr1 = (unsigned char *)ptr1;
    unsigned char *bytePtr2 = (unsigned char *)ptr2;

    // Loop through each byte
    while (size--) {
        // XOR operator is used for swapping values
        *bytePtr1 = *bytePtr1 ^ *bytePtr2; // Temporary value for the swap
        *bytePtr2 = *bytePtr1 ^ *bytePtr2; // Set value at bytePtr2 to the original value of bytePtr1
        *bytePtr1 = *bytePtr1 ^ *bytePtr2; // Set value at bytePtr1 to the original value of bytePtr2

        // Move to the next byte
        bytePtr1++;
        bytePtr2++;
    }
}

int main() {
    // Example usage for integers
    int firstInteger, secondInteger;

    printf("Enter the first integer: ");
    if (scanf("%d", &firstInteger) != 1) {
        printf("Invalid input for the first integer.\n");
        return 1;
    }

    printf("Enter the second integer: ");
    if (scanf("%d", &secondInteger) != 1) {
        printf("Invalid input for the second integer.\n");
        return 1;
    }

    printf("Before swapping: firstInteger = %d, secondInteger = %d\n", firstInteger, secondInteger);
    swap(&firstInteger, &secondInteger, sizeof(int));
    printf("After swapping: firstInteger = %d, secondInteger = %d\n", firstInteger, secondInteger);

    // Example usage for doubles
    double firstDouble, secondDouble;

    printf("Enter the first double: ");
    if (scanf("%lf", &firstDouble) != 1) {
        printf("Invalid input for the first double.\n");
        return 1;
    }

    printf("Enter the second double: ");
    if (scanf("%lf", &secondDouble) != 1) {
        printf("Invalid input for the second double.\n");
        return 1;
    }

    printf("Before swapping: firstDouble = %.2f, secondDouble = %.2f\n", firstDouble, secondDouble);
    swap(&firstDouble, &secondDouble, sizeof(double));
    printf("After swapping: firstDouble = %.2f, secondDouble = %.2f\n", firstDouble, secondDouble);

    // Example usage for characters
    char firstChar, secondChar;

    printf("Enter the first character: ");
    if (scanf(" %c", &firstChar) != 1) {
        printf("Invalid input for the first character.\n");
        return 1;
    }

    printf("Enter the second character: ");
    if (scanf(" %c", &secondChar) != 1) {
        printf("Invalid input for the second character.\n");
        return 1;
    }

    printf("Before swapping: firstChar = %c, secondChar = %c\n", firstChar, secondChar);
    swap(&firstChar, &secondChar, sizeof(char));
    printf("After swapping: firstChar = %c, secondChar = %c\n", firstChar, secondChar);

    return 0;
}
