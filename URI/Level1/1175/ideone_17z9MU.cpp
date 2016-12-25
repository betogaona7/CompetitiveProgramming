#include <stdio.h>

int main() {
	int arr[20];
	int i = 0;
	while(scanf("%d", &arr[i]), i < 20){
		i +=1;
	}
	int aux = 0;
	for(int i = 0, j = 19; i < 10; i++, j--){
		aux = arr[j];
		arr[j] = arr[i];
		arr[i] = aux;
	}
	for(int i = 0; i < 20; i++){
		printf("N[%d] = %d\n", i, arr[i]);
	}
	return 0;
}