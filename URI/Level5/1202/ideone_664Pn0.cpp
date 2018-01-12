#include <iostream>
#include <string> 
#include <stdio.h>

using namespace std;

int todecimal(long long n){
	int factor = 1, total = 0;
	while(n != 0){
		total += (n%10)*factor;
		n /= 10;
		factor *= 2;
	}
	return total;
}

long long int fibonacci(int n){
	long long int current = 0, previous = 0, after = 1;
	for (int i = 0; i < n; i++){
		current = previous + after;
		previous = after;
		after = current;
	}
	
	if(n < 7){
		printf("00%lld\n", previous);
	}else if (n < 11){
		printf("0%lld\n", previous);
	}else{
		printf("%lld\n", previous);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n;  i++){
		long long binary;
		scanf("%lld", &binary);
		fibonacci(todecimal(binary));
	}
	return 0;
}
