#include <stdio.h>

int main() {
	float average = 0, score;
	int val = 0;
	
	while(val < 2){
		scanf("%f", &score);
		if(score >= 0 && score <= 10){
		    average += score;
			val += 1;
		}else{
			printf("nota invalida\n");
		}
	}
	printf("media = %.2f\n", average/2);
	
	return 0;
}