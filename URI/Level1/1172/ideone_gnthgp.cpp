#include <stdio.h>

int main() {
	int arr[10];
	int i = 0;
	while(scanf("%d", &arr[i]), i < 10){
		if(arr[i] <= 0){
			arr[i] = 1;
		}
		
		
		i+=1;
	}
	
	for(int i = 0; i < 10; i++){
		printf("X[%d] = %d\n", i, arr[i]);
	}
	return 0;
}