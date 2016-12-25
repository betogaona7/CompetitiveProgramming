#include <stdio.h>

int main() {
	int arr[10];
	int n;
	scanf("%d", &n);
	
	for(int i = n, j = 0; j < 10; j++, n *= 2){
		arr[i] = n;
		printf("N[%d] = %d\n", j , arr[i]);
	}
	
	return 0;
}