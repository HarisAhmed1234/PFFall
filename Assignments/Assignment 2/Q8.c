#include <stdio.h>

int calculate_persistence(int n);

int main() {
    int num;
    while (1) {
        printf("Enter a number or press 0 to exit: ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        } else {
            int persistence = calculate_persistence(num);
            printf("The persistence number of %d is %d\n", num, persistence);
        }
    }

    return 0;
}

int calculate_persistence(int n) {
    int persistence = 0;
    while (n >= 10) {
        int product = 1;
        while (n > 0) {
            product *= n % 10;
            n /= 10;
        }
        n = product;
        persistence++;
    }
    return persistence;
}
