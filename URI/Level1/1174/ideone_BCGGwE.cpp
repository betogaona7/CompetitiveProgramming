#include <stdio.h>


int main() {
	int i = 0;
	float arr[4];
	while(scanf("%f", &arr[i]), i < 4){
		i+=1;
	}
	
	for(int i = 0; i < 4; i++){
		if(arr[i] <= 10){
			printf("A[%d] = %.1f\n", i, arr[i]);	
		}
	}
	return 0;
}