#include <stdio.h>

int main() {
	
	int total = 0, number;
	for(int i = 0; i < 5; i++){
		scanf("%d",&number);
		if(number%2 == 0){
			total += 1;
		}
	}
	
	printf("%d valores pares\n", total);
	return 0;
}