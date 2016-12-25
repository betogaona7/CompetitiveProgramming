#include <stdio.h>

int main() {
	int hrs, min;
	while(scanf("%d:%d",&hrs, &min) != EOF){
		if(hrs <= 6){
			printf("Atraso maximo: 0\n");
		}else if(hrs == 7 && min == 0){
			printf("Atraso maximo: 0\n");
		}else{
			printf("Atraso maximo: %d\n", ((hrs-7)*60)+min);
		}
	}
	return 0;
}