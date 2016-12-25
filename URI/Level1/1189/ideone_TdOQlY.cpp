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
	int aux = 11, temp = 1, temp2 = 1, j = 0;
	
	for(int i = 1; temp < aux; i++){
		while(j < temp2){
			//printf("%d %d\n", temp, j);
			total += m[temp][j];
			j++;
		}
		temp += 1;
		aux --;
		temp2 = temp;
		j = 0;
	}
	
	temp = 6;
	temp2 = 4;
	
	for(int i = 11; temp < i; i--){
		while(j <= temp2){
			//printf("%d %d\n", temp, j);
			total += m[temp][j];
			j++;
		}
		temp += 1;
		temp2--;
		j = 0;
	}

	total += (m[9][0] + m[9][1] + m[10][0]);
	
	if(letter == 'S'){
		printf("%.1lf\n", total);
	}else if(letter == 'M'){
		printf("%.1lf\n", total/30.0);
	}
	
	return 0;
}