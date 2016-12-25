
#include <stdio.h>

int main() {
	
	int n;
	
	scanf("%d", &n);
	int arr[n];
	
	int aux = 0;
	while(aux < n){
		scanf("%d", &arr[aux]);
		aux += 1;
	}
	
	for(int i = 0; i < n; i++){
		
		//printf("Element: %d\n",arr[i]); 
		if(arr[i] == 0){
			printf("NULL\n");
		}
		else if (arr[i]%2 == 0){
			if(arr[i] > 0){
				printf("EVEN POSITIVE\n");
			}else{
				printf("EVEN NEGATIVE\n");
			}
		}else if(arr[i]%2 != 0) {
			if(arr[i] > 0){
				printf("ODD POSITIVE\n");
			}else{
				printf("ODD NEGATIVE\n");
			}
		}
	}
	
	return 0;
}