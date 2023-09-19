#include <stdio.h>

int main() {
    char option;

    printf("Are you sure to delete (Y/y) / (N/n)?\n ");
    scanf("%c", &option);

    switch (option) {
        case 'Y':
            printf("Deleted successfully\n");
            break;
        case 'y':
            printf("Deleted successfully\n");
            break;
        case 'N':
            printf("Delete cancelled\n");
            break;
        case 'n':
            printf("Delete cancelled\n");
            break;
        default:
            printf("Choose the right option\n");
    }

    return 0;
}
