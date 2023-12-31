/*
 * Name: Haris Ahmed	
 * Date: 17/10/23
 * Description: The elements of an array to be rotated  about a pivot 'd'
 */

#include <stdio.h>

void showArray(int *arr, int N) {
    for (int n = 0; n < N; n++) {
        printf("%d ", *(arr + n));
    }
} // end showArray(int *, int)

void rotateElements(int *arr, int N, int p) {
    for (int k = p - 1, c = 0; k >= 0; k--, c++) {
        for (int j = k; j + 1 < N - c; j++) { 
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
} // end showArray(int *, int, int)

int main() {
    int arr[100];
    int N, d;
    do {
        printf("Enter elements: ");
        scanf("%d", &N);
    } while (N > 100 || N < 1);

    for (int i = 0; i < N; i++) {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    } 

    printf("\nEnter pivot: ");
    scanf("%d", &d);

    rotateElements(arr, N, d);
    
    showArray(arr, N);

    return 0;
} // end main()
