#include <stdio.h>
int main() {
	
	int j = 7;
	for(int i = 1; i <= 9; i+= 2){
		for(int k = 0; k < 3; k++){
			printf("I=%d J=%d\n", i, j);
			j -= 1;
		}
		j+= 5;
	}
	return 0;
}