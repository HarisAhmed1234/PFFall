#include <stdio.h>;
int main(){
	int num1,num2,n=0,divisor,divident,quotient,remainder;
	printf("Enter first number: ");
	scanf("%d", &num1);
	printf("Enter second number: ");
	scanf("%d", &num2);
	while(num1>=num2){
		num1=num1-num2;
		n++;
	}
	remainder=num1;
	
	printf("The quotient is %d\n", n);
	printf("The remainder is %d\n", remainder );
	return 0;
}
