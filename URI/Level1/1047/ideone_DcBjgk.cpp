#include <stdio.h>

int main() {
	int h1, m1, h2, m2, total;
	scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
	
	if(h1 < h2){
		total = (((h2*1440)/24)+m2) - (((h1*1440)/24) + m1);
	}else{
		total = (1440 - (((h1*1440)/24)+m1)) + (((h2*1440)/24) + m2);
	}
	
	int hrs = total/60;
	int min = total-(hrs*60);
	
	if(hrs == 0 && min == 0){
		printf("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)\n");
	}else{
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hrs, min);
	}
	
	return 0;
}