#include <stdio.h>

long long int factorial(int n, long long int prev){ 
	long long int result = prev;
	
	if(n > 0){
		result *= n;
		factorial(n-1, result); 
	}else{
		return result;
	}
}

int main() {
	long long int resulta, resultb;
	int a, b;
	
	while(scanf("%d %d", &a, &b) != EOF){
		if(a == 0){
			a = 1;
		}
		if(b == 0){
			b = 1;
		}
		if(a != 0 && b != 0){
			printf("%lld\n", factorial(a,1)+factorial(b,1));
		}
	}
	return 0;
}
