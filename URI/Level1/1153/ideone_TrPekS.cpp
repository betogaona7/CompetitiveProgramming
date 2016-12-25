#include <stdio.h>

int main() {
	int n, total = 1;
	scanf("%d", &n);
	
	for(int i = n; i > 0; i--){
		total *= i;
	}
	printf("%d\n",total);
	return 0;
}