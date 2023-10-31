#include <stdio.h>

int factorial(int n);

int main() {
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int result = factorial(n);
        printf("Factorial of %d = %d\n", n, result);
    }

    return 0;
}

int factorial(int n) {
    if (n < 0) {
        return 0; 
    } else if (n == 0 || n == 1) {
        return 1; 
    } else {
        int result = 1,i;
        for ( i = 1; i <= n; i++) {
            result *= i; // Calculate the factorial
        }
        return result;
    }
}
