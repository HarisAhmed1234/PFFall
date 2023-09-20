#include <stdio.h>

int main() {
    float original_price, discount, save, amount_after_discount;
    printf("Enter the total amount spent: ");
    scanf("%f", &original_price);

    if (original_price > 1999) {
        if (original_price <= 4000) {
            discount = 0.2 * original_price; // 20% discount
        } else if (original_price <= 6000) {
            discount = 0.3 * original_price; // 30% discount
        } else {
            discount = 0.5 * original_price; // 50% discount
        }

        save = discount;
        amount_after_discount= original_price - discount;

        // Print the results
        printf("Actual amount: %f\n", original_price);
        printf("Saved amount: %f\n", save);
        printf("Amount after discount: %f\n", amount_after_discount);
    } else {
        printf("No discount: %f\n", original_price);
    }

    return 0;
}
