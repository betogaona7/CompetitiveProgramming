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
	
	/*for(int i = 0, aux = 0; i < 11; i++, aux++){
		for(int j = 10; j >= 0; j--){
			if(j-aux < 0){
				break;
			}
			total += m[i][j-aux];
		}
	}*/
	int j = 1, temp = 1;
	for(int i = 11; i > 0; i--){
		while(j < 12){
			total += m[i][j];
			j += 1;
		}
		temp += 1;
		j = temp;
	}

	if(letter == 'S'){
		printf("%.1lf\n", total);
	}else if(letter == 'M'){
		printf("%.1lf\n", total/66.0);
	}
	
	return 0;
}