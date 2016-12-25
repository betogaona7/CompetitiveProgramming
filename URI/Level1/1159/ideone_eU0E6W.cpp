#include <stdio.h>

int main() {
	int n, total = 0;
	while(scanf("%d", &n), n != 0){
		if(n%2 != 0){
			n+=1;
		}
		for(int i = n, j = 0; j < 5; j++, i +=2){
			total += i;
		}
		printf("%d\n", total);
		total = 0;
	}
	return 0;
}