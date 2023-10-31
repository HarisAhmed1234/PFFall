#include <stdio.h>

int main() {
    int n;
    printf("Enter NxN value: ");
    scanf("%d", &n);

    int arr[n][n];

    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int num = 1;

    // Inwards pattern
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            arr[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            arr[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            arr[bottom][i] = num++;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            arr[i][left] = num++;
        }
        left++;
    }

    // Print inwards pattern
    printf("Inwards Pattern:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    // Reset array for outwards pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }

    // Outwards pattern
    left = 0;
    right = n - 1;
    top = 0;
    bottom = n - 1;
    num = n * n;

    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; i++) {
            arr[top][i] = num--;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            arr[i][right] = num--;
        }
        right--;

        for (int i = right; i >= left; i--) {
            arr[bottom][i] = num--;
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            arr[i][left] = num--;
        }
        left++;
    }

    // Print outwards pattern
    printf("\nOutwards Pattern:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
