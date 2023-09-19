#include <stdio.h>

int main() {
    char operator;
    int number1, number2, result;

    printf("Enter an operator (+, -, *, /)= ");
    scanf(" %c", &operator);

    printf("Enter number 1= ");
    scanf("%d", &number1);
    printf("Enter number 2= ");
    scanf("%d", &number2);

    if (operator == '+') {
        result = number1 + number2;
    } else if (operator == '-') {
        result = number1 - number2;
    } else if (operator == '*') {
        result = number1 * number2;
    } else if (operator == '/') {
        if (number2 != 0) //to avoid infinity
        {
            result = number1 / number2;
        } else {
            printf("Error: Division by zero is not allowed.\n");
            return 1; 
        }
    } else {
        printf("Invalid operator!\n");
        return 1; 
    }

    printf("Result: %d\n", result);

    return 0;
}

