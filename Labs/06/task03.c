#include <stdio.h>
int main(){
	int num1,num2;
	printf("Enter the first number: ");
	scanf("%d",&num1);
	printf("Enter the second number: ");
	scanf("%d",&num2);
	int GCD=0;
	if(num2>num1){
		GCD=num2;
	}
	else{
		GCD=num1;
	}
	for (GCD>0; GCD--;){
		if (num2%GCD==0 && num1%GCD==0)
		{
			break;
		}
	}
	printf("The GCD is %d\n",GCD);
	int LCM= num2*num1/GCD;
	
	printf("The LCM is %d\n", LCM);
}
