#include <stdio.h>

int main() {
	
	float sum = 0, number;
	int total = 0;
	
	for(int i = 0; i < 6; i++){
		scanf("%f", &number);
		
		if(number > 0){
			sum = sum + number;
			total = total + 1;
		}
	}
	
	printf("%d valores positivos\n%.1f\n", total, sum/total);
	
	
	return 0;
}