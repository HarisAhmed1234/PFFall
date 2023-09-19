#include <stdio.h>

int main() {
    int number_of_integers, count = 0, input_value, sum_of_squares = 0;
	printf("Enter the number of inputs: ");
    scanf("%d", &number_of_integers);

    while (count < number_of_integers) { 
        printf("Enter integer %d: ", count + 1);
        scanf("%d", &input_value);
        sum_of_squares = sum_of_squares + (input_value * input_value);
        count=count + 1;
    }
    printf("The sum of the squares is: %d\n", sum_of_squares);

    return 0;
}
