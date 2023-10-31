#include <stdio.h>

void reverse(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        // Swap elements pointed to by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers toward the center
        start++;
        end--;
    }
}

int main() {
    int arr[10];
    int size = 10;
	int i;
    printf("Enter 10 integers:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    reverse(arr, size);

    printf("Reversed array:\n");
    for ( i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
