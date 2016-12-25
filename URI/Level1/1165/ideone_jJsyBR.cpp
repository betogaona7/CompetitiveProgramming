#include <stdio.h>

int main() {
	int n, a, total = 0;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &a);
		for(int i = a; i > 0; i--){
			if(a%i == 0){
				total += i;
			}
		}
		if(total == (a + 1)){
			printf("%d eh primo\n", a);
		}else{
			printf("%d nao eh primo\n", a);
		}
		total  = 0;
	}
	return 0;
}