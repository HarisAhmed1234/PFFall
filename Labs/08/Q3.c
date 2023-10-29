/*
Programmer: Haris Ahmed
Description: Searching for a specific character using strchr function
Date: 29/10/2023
*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter any text: ");
    
    if (scanf("%99[^\n]", str) == 1) {
        char searchChar = 'a';
        int count = 0;
        char *ptr = str;

        while ((ptr = strchr(ptr, searchChar)) != NULL) {
            count++;
            ptr++; // pointer moves towards the next character
        }

        printf("The character 'a' appears %d times in the input string.\n", count);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
