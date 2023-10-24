#include <stdio.h>

int decidecarusage(int num, int day);

int decidecarusage(int num, int day){
	if(num%2==day%2){
		return 1;
	}
	else {
		return 0;
	}
	
}

int main(){
	int num,day;
	printf("Emter numeric part of your cars number plate: ");
	scanf("%d",&num);
	printf("Emter the day: ");
	scanf("%d",&day);
	if (decidecarusage(num,day)){
		printf("car can be used!");
		}else{
				printf("car cannot be used!");
		}
	}
