#include <stdio.h>

int main() {
	
	int i = 0, aux = 0, h = 0, p  = 0, d;
	
	while(i < 10){
		scanf("%d", &d);
		
		if(d > aux){
			h = d;
			p = i + 1;
		}
		aux = h;
		i += 1;
	}
	printf("%d\n%d\n", h , p);
	
	return 0;
}