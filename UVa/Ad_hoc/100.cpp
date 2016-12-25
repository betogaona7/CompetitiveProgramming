#include <stdio.h>

int cycleLength(int n){
	int cont = 0;
	while(n > 1){
		if(n == 1){
			break;
		}else{
			if(n%2 != 0){
				n = 3*n+1;
				cont += 1;
			}else{
				n /= 2;
				cont += 1;
			}
		}
	}
	return cont + 1;
}

int main() {
	
	int a, b, max = 0, temp = 0, aux1, aux2;
	
	while(scanf("%d %d", &a, &b) != EOF){
		aux1 = a;
		aux2 = b;
		
		if(a > b){
			a = aux2;
			b = aux1;
		}
		
		while(a <= b){
			temp = cycleLength(a);
			if(max < temp){
				max = temp;
			}
			a += 1; 
		}
		printf("%d %d %d\n", aux1, aux2, max);
		max = 0;
	}
	return 0;
}