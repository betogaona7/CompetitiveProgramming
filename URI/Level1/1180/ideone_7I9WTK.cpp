#include <stdio.h>

int main() {
	int n, p = 0;
	scanf("%d", &n);
	int arr[n];
	
	
	int i = 0;
	while(scanf("%d", &arr[i]), i < n){
		i += 1;
	}
	
	int temp = arr[0];
	
	for(int i = 0; i < n; i++){
		if(arr[i] < temp){
			temp = arr[i];
			p = i;
		}
	}
	
	printf("Menor valor: %d\nPosicao: %d\n", temp, p);
	return 0;
}