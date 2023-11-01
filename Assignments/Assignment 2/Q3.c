#include <stdio.h>

int main() {
    int morningAvailability[5], eveningAvailability[5];
    int morningPrices[5], eveningPrices[5];

    for (int day = 0; day < 5; day++) {
        printf("Day %d - Morning (0 or 1): ", day + 1);
        scanf("%d", &morningAvailability[day]);
        printf("Day %d - Evening (0 or 1): ", day + 1);
        scanf("%d", &eveningAvailability[day]);
    }

    printf("Enter prices for morning flights:\n");
    for (int day = 0; day < 5; day++) {
        printf("Day %d: $", day + 1);
        scanf("%d", &morningPrices[day]);
    }

    printf("Enter prices for evening flights:\n");
    for (int day = 0; day < 5; day++) {
        printf("Day %d: $", day + 1);
        scanf("%d", &eveningPrices[day]);
    }

    int bestMorningOption = -1;
    int bestEveningOption = -1;
    int cheapestMorningPrice = -1;
    int cheapestEveningPrice = -1;

    for (int day = 0; day < 5; day++) {
        if (morningAvailability[day] == 1) {
            if (morningPrices[day] < cheapestMorningPrice || cheapestMorningPrice == -1) {
                cheapestMorningPrice = morningPrices[day];
                bestMorningOption = day;
            }
        }
        if (eveningAvailability[day] == 1) {
            if (eveningPrices[day] < cheapestEveningPrice || cheapestEveningPrice == -1) {
                cheapestEveningPrice = eveningPrices[day];
                bestEveningOption = day;
            }
        }
    }

    printf("1. Best option based on time and price:\n");
    printf("Morning: %d on Day %d for $%d\n", morningAvailability[bestMorningOption], bestMorningOption + 1, cheapestMorningPrice);
    printf("Evening: %d on Day %d for $%d\n", eveningAvailability[bestEveningOption], bestEveningOption + 1, cheapestEveningPrice);

    int selectedDay;
    printf("Enter the desired day (1 to 5): ");
    scanf("%d", &selectedDay);
    selectedDay--;

    if (selectedDay >= 0 && selectedDay < 5) {
        printf("4. Availability and price for Day %d:\n", selectedDay + 1);
        printf("Morning: %d for $%d\n", morningAvailability[selectedDay], morningPrices[selectedDay]);
        printf("Evening: %d for $%d\n", eveningAvailability[selectedDay], eveningPrices[selectedDay]);
    } else {
        printf("4. Invalid day selection.\n");
    }
    return 0;
}
