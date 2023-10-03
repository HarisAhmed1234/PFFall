#include <stdio.h>
int main(){
int number,count=1,sum=0;
printf("Enter any Number: ");
scanf("%d",&number);
while (count<number){
	if(number%count==0){
	sum= sum + count;
	}
    count++;
}
	if(sum==number){
	printf("its a perfect number");
	}
	if(sum!=number){
	printf("its not a perfect number");
	}
}
