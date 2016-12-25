#include <stdio.h>
int main() {
	
	for(int i = 1; i <= 9; i+=2){
		for(int t = 0, j = 7; t < 3; t++, j -= 1){
			printf("I=%d J=%d\n", i , j);
		}
	}
	return 0;
}