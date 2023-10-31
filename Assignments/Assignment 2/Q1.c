/*
Programmer:  Haris Ahmed
Description: representing the batting performance of a cricket team.
Date: 31/10/2023
*/
}
#include <stdio.h>

int main() {
    int players, innings;

    // Input the number of players and innings
    printf("Enter the number of players: ");
    scanf("%d", &players);
    printf("Enter the number of innings: ");
    scanf("%d", &innings);

    // 2D array
    int battingPerformance[players][innings];

    // Batting performance of players as input
    for (int i = 0; i < players; i++) {
        printf("Enter batting performance for player %d:\n", i + 1);
        for (int j = 0; j < innings; j++) {
            printf("Inning %d: ", j + 1);
            scanf("%d", &battingPerformance[i][j]);
        }
    }

    // Calculate and display statistics for each player
    for (int i = 0; i < players; i++) {
        int totalRuns = 0;
        int highestScore = 0;
        int centuries = 0;
        int halfCenturies = 0;

        for (int j = 0; j < innings; j++) {
            totalRuns += battingPerformance[i][j];

            if (battingPerformance[i][j] > highestScore) {
                highestScore = battingPerformance[i][j];
            }

            if (battingPerformance[i][j] >= 100) {
                centuries= centuries + 1;
            } else if (battingPerformance[i][j] >= 50) {
                halfCenturies= halfCenturies +1;
            }
        }

        double averageRuns = (double)totalRuns / innings;

        printf("\nStats for Player %d:\n", i + 1);
        printf("Total runs scored are: %d\n", totalRuns);
        printf("Average runs per inning: %f\n", averageRuns);
        printf("Highest runs made in a match: %d\n", highestScore);
        printf("Number of centuries: %d\n", centuries);
        printf("Number of half-centuries: %d\n", halfCenturies);
    }

    return 0;
}
