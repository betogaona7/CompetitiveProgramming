#include <stdio.h>

int main() {
	int t;
	int arr[1000];
	scanf("%d", &t);
	for(int i = 0, j= 0; i < 1000; i++, j++){
		arr[i] = j;
		if(j == t-1){
			j = -1;
		}
		printf("N[%d] = %d\n", i, arr[i]);
			
	}
	return 0;
}