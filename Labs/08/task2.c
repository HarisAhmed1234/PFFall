#include <stdio.h>

int multiplication(int a, int b);
int division(int a, int b);
int subtraction(int a, int b);
int addition(int a, int b);

int multiplication(int a, int b) {
    int result = a * b;
    return result;
}

int division(int a, int b) {
    if (b == 0) {
        printf("Division by zero is not allowed.\n");
        return 0;  // Return 0 as an error value
    }
    int result = a / b;
    return result;
}

int subtraction(int a, int b) {
    int result = a - b;
    return result;
}

int addition(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int num1, num2;
    char operator;

    printf("Enter the first value: ");
    scanf("%d", &num1);
    printf("Enter the second value: "); // Changed from "num1" to "num2"
    scanf("%d", &num2);

    printf("Enter the operator: ");
    scanf(" %c", &operator);  // Corrected operator input and added a space before %c

    int result;

    if (operator == '+') {
        result = addition(num1, num2);
    } else if (operator == '*') {
        result = multiplication(num1, num2);
    } else if (operator == '/') {
        result = division(num1, num2);
    } else if (operator == '-') {
        result = subtraction(num1, num2);
    } else {
        printf("Invalid operator.\n");
        return 1;  // Return an error code
    }

    printf("The result is: %d\n", result);

    return 0;
}
