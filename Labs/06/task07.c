#include <stdio.h>
int main() {
    int n, sum = 0;
	printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
	int arr[n];
  printf("Enter %d elements:\n", n);
    for (int a = 0; a<n; a++) {
        scanf("%d", &arr[a]);
        sum = sum + arr[a];
    }
	 printf("Sum of the elements is %d\n", sum);
	return 0;
}
