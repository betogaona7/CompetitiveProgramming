#include <stdio.h>

int main() {
	int l;
	char op;
	
	float arr[12][12];
	
	scanf("%d %c", &l, &op);
	for(int i = 0; i < 12; i++){
		for(int j = 0; j < 12; j++){
			scanf("%f", &arr[i][j]);
		}
	}
	
	
	int sum = 0;
	for(int j = 0; j < 12; j++){
		sum += arr[l][j];
	}	
	
	if(op == 'S'){
		printf("%.1f\n", (float)sum);
	}else if(op == 'M'){
		printf("%.1f\n", (float)sum/12);
	}
	
	return 0;
}