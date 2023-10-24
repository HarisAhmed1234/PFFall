#include <stdio.h>

void swapintegers(int *a, int *b);

void swapintegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);

    swapintegers(&a, &b);  // Pass the addresses of a and b

    printf("The value of a is: %d\n", a);
    printf("The value of b is: %d\n", b);

    return 0;
}
