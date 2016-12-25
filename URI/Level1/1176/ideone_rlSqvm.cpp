#include <stdio.h>

int main() {
	int n, v;
	scanf("%d", &v);
	while(v--){
		scanf("%d", &n);
		long long int arr[n];
		
		for(int i = n, j = 0; i > 0; i--, j++){
			if(j < 2){
				arr[j] = 1;
			}else{
				arr[j] = arr[j-1] + arr[j-2];
			}
		}
		if(n == 0){
			printf("Fib(0) = 1\n");
		}else{
			printf("Fib(%d) = %lld\n", n, arr[n-1]);
		}
	}
	return 0;
}