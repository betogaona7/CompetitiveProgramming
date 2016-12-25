#include <stdio.h>

int main() {
	long long int n;
	scanf("%lld", &n);
	do{
		printf("%lld", n%10);
		n /= 10;
	}while(n != 0);
	printf("\n");
	
	return 0;
}