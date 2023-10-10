#include <stdio.h>

int main() {
    int a, b;
    printf("Enter the first integer (a): ");
    scanf("%d", &a);
	printf("Enter the second integer (b): ");
    scanf("%d", &b);    

    if (a <= b) {
        for (int i = a; i <= b; i++) {
            if (i <= 9) {
                switch (i) {
                    case 0: printf("Zero"); break;
                    case 1: printf("One"); break;
                    case 2: printf("Two"); break;
                    case 3: printf("Three"); break;
                    case 4: printf("Four"); break;
                    case 5: printf("Five"); break;
                    case 6: printf("Six"); break;
                    case 7: printf("Seven"); break;
                    case 8: printf("Eight"); break;
                    case 9: printf("Nine"); break;
                }
        } else {
                
                if (i % 2 == 0) {
                    printf("Even ");
                } else {
                    printf("Odd ");
                }
            }
        }
    } else {
        printf("Invalid input.");
    }

    return 0;
}
