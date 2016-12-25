#include <stdio.h>

int main() {
	int n, p, i = 1, aux = 100, pos = 0;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &p);
		if(aux > p){
			aux = p;
			pos = i;
		}
		i += 1;
	}
	printf("%d\n", pos);
	return 0;
}

//8 0 7
//1 2 3