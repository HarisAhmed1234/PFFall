/*
Programmer: Haris Ahmed
Description: C program for a coffee shop that offers discounts based on customer loyalty and purchase history.
Date: 29/10/2023
*/
#include <stdio.h>

// Creating a Function to calculate the discount
double calculateDiscount(double totalPurchaseAmount, int visits) {
    double discount = 0.0;

    // Checking conditions for discount application
    if (visits > 10 && totalPurchaseAmount >= 50.0) {
        discount = 0.15 * totalPurchaseAmount; // 15% discount
    } else if (visits > 5 && totalPurchaseAmount >= 30.0) {
        discount = 0.10 * totalPurchaseAmount; // 10% discount
    }

    return discount;
}

int main() {
    double totalPurchaseAmount;
    int visits;

    // user to input total purchase amount and number of visits
    printf("Enter the total purchase amount: $");
    scanf("%lf", &totalPurchaseAmount);

    printf("Enter the number of visits in the past month: ");
    scanf("%d", &visits);

    if (visits < 0) {
        printf("Invalid number of visits. Please enter a positive value.\n");
    } else {
        double discount = calculateDiscount(totalPurchaseAmount, visits);

        if (discount > 0.0) {
            printf("You qualify for a discount of $%.2lf\n", discount);
        } else {
            printf("No discount applied.\n");
        }
    }

    return 0;
}
