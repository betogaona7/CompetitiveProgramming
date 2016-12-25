#include <stdio.h>

int main() {
	int n, aux = 1;
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			aux *= i;
			printf("%d ", aux);
		}
		printf("%d\n",aux*i);
		aux = 1;
		
	}
	return 0;
}