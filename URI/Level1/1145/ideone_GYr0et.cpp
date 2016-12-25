#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
		for(int i = 1; i <= b; i++){
			for(int j = 0; j < a-1; j++){
				printf("%d ", i++);
			}
			printf("%d\n", i);
		}
	
	return 0;
}