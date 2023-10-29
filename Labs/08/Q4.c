/*
Programmer: Haris Ahmed
Description: Password length validation based on requirements
Date: 24/10/2023
*/

#include <stdio.h>
#include <string.h>

int main() {
    char password[100]; 
    char correctpassword[] = "Secure123"; 

    printf("Enter your password: ");

    int i = 0;
    char c;

    while (i < sizeof(password) - 1) {
        c = getchar();
        if (c == '\n') {
            break; // Stop reading if Enter key is pressed
        }
        password[i] = c;
        i++;
    }

    password[i] = '\0';

    if (i >= 8 && strcmp(password, correctpassword) == 0) {
        printf("Welcome!\n");
    } else {
        printf("Authentication failed. Please check your password.\n");
    }

    return 0;
}
