#include <stdio.h>

int check(int a, int b, int c){
	if((a+b) > c && (b+c) > a && (a+c) > b){
		return 1;
	}else{
		return 0;
	}
}

int main() {
	int a, b, c, d, aux = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	aux += check(a,b,c);
	aux += check(a,b,d);
	aux += check(a,c,d);
	aux += check(c,b,d);
	
	if(aux > 0){
		printf("S\n");
	}else{
		printf("N\n");
	}
	
	
	return 0;
}