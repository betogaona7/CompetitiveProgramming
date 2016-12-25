#include <stdio.h>

int main() {
	char letter;
	
	double m[12][12];
	
	scanf("%c", &letter);
	
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			scanf("%lf", &m[i][j]);
		}
	}
	
	double total = 0;
	int aux = 11, temp = 1, aux2 = 1;
	
	for(int i = 11; i > 6; i--){
		
		for(int j = 1; temp < aux; j++){
			//printf("%d %d\n", i, temp);
			total += m[i][temp];
			temp ++;
		}
		aux2 ++;
		temp = aux2;
		aux--;
	}

	if(letter == 'S'){
		printf("%.1lf\n", total);
	}else if(letter == 'M'){
		printf("%.1lf\n", total/30.0);
	}
	
	return 0;
}