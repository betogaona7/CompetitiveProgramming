#include <stdio.h>

int main() {
	int pos = 0, pares = 0, cero = 0, number;
	for(int i = 0; i < 5; i++){
		scanf("%d",&number);
		if(number%2 == 0){
			pares += 1;
		}
		if(number > 0){
			pos += 1;
		}else if(number == 0){
			cero += 1;
		}
	}
	
	printf("%d valor(es) par(es)\n%d valor(es) impar(es)\n", pares, 5-pares);
	printf("%d valor(es) positivo(s)\n%d valor(es) negativo(s)\n", pos, (5-pos)-cero);
	
	return 0;
}