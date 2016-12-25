#include <stdio.h>

int main() {
	
	int opt = 1, i = 0;
	float s, total = 0;
	
	while(opt == 1){
		while(i < 2){
			scanf("%f", &s);
			if(s >= 0 && s <= 10){
				total += s;
				i += 1;
			}else{
				printf("nota invalida\n");
			}
		}
		printf("media = %.2f\n", total/2);
		printf("novo calculo (1-sim 2-nao)\n");
		
		while(scanf("%d", &opt), opt != 2 && opt != 1){
			printf("novo calculo (1-sim 2-nao)\n");
		}
		if(opt == 2){
			break;
		}
		
		i = 0;
		total = 0;
	}
	return 0;
}