#include <stdio.h>

int main() {
	int x, y, total = 0;
	
	while(scanf("%d %d", &x, &y), x > 0 && y > 0){
		if(x > y){
			for(int i = y; i <= x; i++){
				printf("%d ", i);
				total += i;
			}
			printf("Sum=%d\n", total);
		}else{
			for(int i = x; i <= y; i++){
				printf("%d ", i);
				total += i;
			}
			printf("Sum=%d\n", total);
		}
		total = 0;
	}
	return 0;
}