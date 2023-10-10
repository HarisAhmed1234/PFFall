/*
* Programmer: Haris Ahmed
* Desc: Taking a number from user and counting the sum of their digits
* Date: 10/10/2023
*/
#include <stdio.h>
int main(){
	int number,remainder,sum=0;
	printf("Enter number: ");
	scanf("%d", &number);
	while(number!=0){
	remainder= number%10;
	sum= sum + remainder;
	number=number/10;
	}
	
	printf("The sum of the numbers are %d", sum);
}
