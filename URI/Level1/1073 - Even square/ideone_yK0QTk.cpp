#include <stdio.h>

int main() {
	int aux = 2, n;
	scanf("%d",&n);
	if(n%2 != 0){
		n -= 1;
	}
	while(aux <= n){
		printf("%d^2 = %d\n",aux, aux*aux);
		aux += 2;
	}
	return 0;
}