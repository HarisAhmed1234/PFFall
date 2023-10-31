#include <stdio.h>

int multiply(int a, int b) {
    if (b == 0) {
        return 0; 
    } else if (b > 0) {
        return a + multiply(a, b - 1); // Recursively add 'a' 'b' times.
    } else {
        return -multiply(a, -b); // Handle negative 'b' by negating the result.
    }
}

int main() {
    int num1, num2;

    printf("Enter number one: ");
    scanf("%d", &num1);
    printf("Enter number two: ");
    scanf("%d", &num2);

    int result = multiply(num1, num2);
    printf("Product of %d and %d is %d\n", num1, num2, result);

    return 0;
}
