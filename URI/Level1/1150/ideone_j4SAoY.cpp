#include <stdio.h>

int main() {
	int x , z, total = 0;
	
	scanf("%d", &x);
	
	while(scanf("%d",&z), z <= x){
		scanf("%d",&z);
	}
	int temp = x;
	int aux = aux + 1;
	while(z > temp){
		temp += (x + aux);
		aux += 1;
		total += 1;
	}
	
	printf("%d\n", total+1);
	return 0;
}