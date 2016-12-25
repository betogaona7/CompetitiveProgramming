#include <stdio.h>
int main() {
	int n; 
	scanf("%d",&n);
	
	int i = 1;
	while(i < 1000){
		if(i%n == 2){
			printf("%d\n", i);
		}	
		i += 1;
	}
	return 0;
}