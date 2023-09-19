#include <stdio.h>

int main() {
    int total_distance = 10 + 5 + 15 + 10;
    int fuel_consumption_rate = 2;
    int total_fuel_consumption;
    total_fuel_consumption= total_distance * fuel_consumption_rate;
    
    printf("Total distance: %d km\n", total_distance);
    printf("Total fuel consumption: %d liters\n", total_fuel_consumption);

    return 0;
}
