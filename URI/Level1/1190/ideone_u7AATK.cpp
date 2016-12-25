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
	int aux = 10;
	for(int i = 1; i < 6; i++){
		for(int j = 11; j > aux; j--){
			//printf("%d %d\n", i, j);
			total += m[i][j];
		}
		aux --;
	}
	
	aux = 6;
	for(int i = 6; i < 11; i++){
		for(int j = 11; j > aux; j--){
			//printf("%d %d\n", i , j);
			total += m[i][j];
		}
		aux++;
	}
	
	if(letter == 'S'){
		printf("%.1lf\n", total);
	}else if(letter == 'M'){
		printf("%.1lf\n", total/30.0);
	}
	
	return 0;
}