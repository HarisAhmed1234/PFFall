int main() {
    char operator;
    int number1, number2, result;

    printf("Enter an operator (+, -, *, /)= ");
    scanf(" %c", &operator);

    printf("Enter number 1= ");
    scanf("%d", &number1);
    printf("Enter number 2= ");
    scanf("%d", &number2);

    switch(operator)
      {
        case '+':
            result = number1 + number2;
            break;
        case '-':
            result = number1 - number2;
            break;
        case '*':
            result = number1 * number2;
            break;
        case '/':
            if (number2 != 0)
            {
                result = number1 / number2;
            } else {
                printf("Error: INFINITY\n");
                return 1; 
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}
