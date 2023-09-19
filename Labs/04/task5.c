#include <stdio.h>

int main() {
    int d1, m1, y1;
    int d2, m2, y2;

    printf("Enter the date of birth for person 1 (dd mm yyyy): ");
    scanf("%d %d %d", &d1, &m1, &y1);

    printf("Enter the date of birth for person 2 (dd mm yyyy): ");
    scanf("%d %d %d", &d2, &m2, &y2);

    if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2))
    {
        printf("Person 1 is older.\n");
    } 
    else if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2))
    {
        printf("Person 2 is older.\n");
    } 
    else {
        printf("Both persons are of the same age.\n");
    }

    return 0;
}
