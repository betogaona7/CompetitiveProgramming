#include <stdio.h>

int main() {
	int n, x, y;
	float num;
	
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &x, &y);
		if(y != 0){
			num = (float)x/(float)y;
			printf("%.1f\n", num);
		}else{
			printf("divisao impossivel\n");
		}
	}
	return 0;
}