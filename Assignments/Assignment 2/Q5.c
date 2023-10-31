#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Ramanujan numbers less than %d^3:\n", n);

    for (int num = 1; num < n * n * n; num++) {
        int count = 0;
        for (int i = 1; i * i * i < num; i++) {
            int j = round(cbrt(num - i * i * i));
            if (j >= i && i * i * i + j * j * j == num) {
                count++;
            }
        }
        if (count == 2) {
            printf("%d\n", num);
        }
    }

    return 0;
}
