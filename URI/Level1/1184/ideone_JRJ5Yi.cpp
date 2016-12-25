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
	
	float total = 0;
	int j = 0;
	for(int i = 1; i < 12; i++){
		while(j < (i)){
			total += m[i][j];
			j += 1;
		}
		j = 0;
	}


	if(letter == 'S'){
		printf("%.1lf\n", total);
	}else if(letter == 'M'){
		printf("%.1lf\n", total/66.0);
	}
	
	return 0;
}