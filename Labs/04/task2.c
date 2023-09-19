#include <stdio.h>

int main() {
int n; 
printf("Enter the positive value of n: ");

scanf("%d", &n);

int line = 1;
int j;
while (line<=n){
int j=1;      
while (j<=n){
           printf("* ");
       j=j+1;
    } //end while j<=n
  printf("\n");
  line=line+1;
}
return 1;
}//end main
