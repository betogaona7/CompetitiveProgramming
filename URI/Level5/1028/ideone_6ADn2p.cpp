#include <stdio.h>

int mdc(int x, int y){
	int aux;
	while((y%x) != 0){
		aux = x;
		x = y%x;
		y = aux;
	}
	return x;
}

int main() {
	int n, x, y, aux;
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &x, &y);
		if(y < x){
			aux = x;
			x = y;
			y = aux;
		}
		printf("%d\n", mdc(x,y));
	}
	return 0;
}
