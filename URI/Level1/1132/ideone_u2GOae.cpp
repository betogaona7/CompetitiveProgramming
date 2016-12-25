#include <stdio.h>

int main() {
	int x, y, total = 0;
	
	scanf("%d %d", &x, &y);
	
	if(x != y){
		if(x > y){
			for(int i = y; i < x; i++){
				if((i%13) != 0){
					total += i;
				}
			}
		}else{
			for(int i = x; i <= y; i++){
				if((i%13) != 0){
					total += i;
				}
			}
		}
		printf("%d\n", total);
	}
	
	else{
		if((x%13) == 0){
			printf("%d\n", x);
		}else{
			printf("0");
		}
	}
	
	return 0;
}