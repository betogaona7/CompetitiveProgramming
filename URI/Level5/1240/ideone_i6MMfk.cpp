#include <stdio.h>
#include <math.h>

int length(long long int num){
	int cont = 0;
	while(num){
		num /= 10;
		cont++;
	}
	return cont;
}

int main() {
	int n;
	long long int a, b, value, len;
	scanf("%d", &n);
	while(n--){
		scanf("%lld %lld", &a, &b);
		len = ceil(pow(10,length(b)));
		value = a%len;
		
		if(value == b){
			printf("encaixa\n");
		}else{
			printf("nao encaixa\n");
		}
	}
	return 0;
}