#include <stdio.h> 
int main(){
	int i, sum; 
	printf("Enter the size of the array:"); 
	scanf("%d", &i);
 	int arr[i]; 
	printf("Enter %d elements:\n", i); 
	for(int j=0; j<i; j++){ 
		printf("Element %d:", j+1); 
		scanf("%d", &arr[j]);
	} 
	int min = arr[0];
        int max = arr[0];
	for(int j=1; j<i; j++){
		if(arr[j] < min){
			min = arr[j];
		}
		if(arr[j] > max){
			max = arr[j];
		}
	}
	printf("Minimum number is: %d\n", min);
	printf("Maximum number is: %d\n", max);
return 0;
}
