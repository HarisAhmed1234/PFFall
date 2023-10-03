#include <stdio.h>
int main(){
int i=0,j=1,k=1,sum=0;
for(i=j+k;i<10000;){
i=j+k;
if(i>10000){
	break;
}
j=k;
k=i;
printf("%d\n",i);
 
 if (i%3==0 || i%5==0 || i%7==0){
 	sum = sum + i;
 }
}
printf("The sum of the number is: %d", sum);
}
