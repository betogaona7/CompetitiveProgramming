#include <stdio.h>

int main() {
	int opt, a, b, i = 0, g = 0, e = 0, n = 0;
	do{
		scanf("%d %d", &a, &b);
		if(a > b){
			i += 1;
		}else if(b > a){
			g += 1;
		}else{
			e += 1;
		}
		printf("Novo grenal (1-sim 2-nao)\n");
		n += 1;
	}while(scanf("%d", &opt), opt == 1);
	
	printf("%d grenais\nInter:%d\nGremio:%d\nEmpates:%d\n",n,i,g,e);
	if(i > g){
		printf("Inter venceu mais\n");
	}else if( g > i){
		printf("Gremio venceu mais\n");
	}else{
		printf("Nao houve vencedor\n");
	}
	return 0;
}