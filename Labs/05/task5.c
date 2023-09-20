#include <stdio.h>

int main() {
	
	char inputChar; 
	printf("Enter a character: ");
	scanf("%c", &inputChar);
	printf("\n");
	
	if (inputChar >= 97 && inputChar <= 122)
	{
		printf("It's a small case alphabet.\n");
	}
	else if (inputChar >= 65 && inputChar <= 90)
	{
		printf("It's a large case alphabet.\n");
	}
	else if (inputChar >= 48 && inputChar <= 57)
	{
		printf("It's a digit.\n");
	}
	else 
	{
		printf("It's a special character.");
	}
}

