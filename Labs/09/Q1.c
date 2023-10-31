/*
Programmer: Haris Ahmed
Description: swapping values using functions
Date: 31/10/2023
*/
// j and k values are not swapped because b was not assigned the value of temp and the printf statement is used right after calling a function, it should be used in the swap function printing a and b as values of j and k
#include <stdio.h>

void swap(int a, int b){
int temp= a;
	a=b;
	b=temp;
	printf("j=%d, k=%d\n", a,b);
}

int main(){
	int j=2,k=5;
	printf("j=%d, k=%d\n", j,k);
	swap(j,k);
	return 0;
}
