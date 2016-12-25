#include  <stdio.h>

int main() {
	int temp[3];
	int arr[3];
	int i = 0;
	
	while(i < 3){
		scanf("%d", &arr[i]);
		temp[i] = arr[i];
		i += 1;
	}
	
	bool swapped;
	do{
		swapped = false;
		for(int i = 0; i < 2; i++){
			if(temp[i] > temp[i+1]){
				int tempo = temp[i+1];
				temp[i+1] = temp[i];
				temp[i] = tempo;
				swapped = true;
			}
		}
	}while(swapped == true);
	
	for(int i = 0; i < 3; i++){
		printf("%d\n", temp[i]);
	}
	printf("\n");
	for(int i = 0; i < 3; i++){
		printf("%d\n", arr[i]);
	}
	return 0;
}