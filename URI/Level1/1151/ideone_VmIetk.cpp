#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	
	
	for(int i = 0; i < n-1; i++){
		arr[i] = i;
		if(i < 2){
			printf("%d ", i);
		}else{
			arr[i] = arr[i-1] + arr[i-2];
			printf("%d ", arr[i]);
		}
	}
	printf("%d\n", arr[n-2] + arr[n-3]);
	
	return 0;
}