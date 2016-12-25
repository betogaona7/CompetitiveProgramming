#include <stdio.h>

int main() {
	int n, t;
	scanf("%d", &n);
	
	while(n--){
		scanf("%d", &t);
		if(t%2 == 0){
			printf("0\n");
		}else{
			printf("1\n");
		}
	}
	return 0;
}