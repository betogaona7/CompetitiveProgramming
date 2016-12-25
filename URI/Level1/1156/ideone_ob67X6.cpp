#include <stdio.h>

int main() {
	float s = 0;
	for(int i = 3, j= 2; i <= 39; i+=2, j*=2){
		s += (float)i/(float)j;
	}
	printf("%.2f\n", s+1);
	return 0;
}