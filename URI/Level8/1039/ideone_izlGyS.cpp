#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
	int r1, x1, y1, r2, x2, y2;
	float distance = 0;
	
	while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF){
		distance = sqrt( (pow((x2-x1),2)) + (pow((y2-y1),2)));
		
		if(distance > (r1+r2)){
			printf("MORTO\n");
		}else if(distance <= (float)(r1 - r2)){
			printf("RICO\n");
		}else{
			printf("MORTO\n");
		}
	}	
	return 0;
}