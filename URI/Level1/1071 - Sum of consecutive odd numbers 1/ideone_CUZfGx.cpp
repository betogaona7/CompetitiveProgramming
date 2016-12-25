#include <stdio.h>
int main() {
	int a, b, odd = 0;
	scanf("%d %d",&a, &b);
	
	if(a > b){
		int aux = a - b;
		
		if(b%2 == 0){
			b += 1;
		}else{
			b += 2;
		}
		if(a%2 == 0){
			a += 1;
		}
		
		while(a  > b){
			a -= 2;
			odd += a;
		}
	}else{
		int aux = b - a;
		
		if(a%2 == 0){
			a += 1;
		}else{
			a += 2;
		}
		if(b%2 == 0){
			b += 1;
		}
		
		while(b  > a){
			b -= 2;
			odd += b;
		}
		
	}
	
	printf("%d\n", odd);
			
	return 0;
}