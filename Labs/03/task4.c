#include <stdio.h>

int main() {
    float origprice = 1500.0;
    float discpercentage = 20.0; // 20% discount
    float SP;//SALE PRICE
    float discountAmount;
    discountAmount = (origprice * discpercentage) / 100.0;
    SP = origprice - discountAmount;
    printf("The sale price is Rs. %f\n", SP);
    return 0;
}
