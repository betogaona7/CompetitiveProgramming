#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n), n != 0){
		for(int i = 1; i < n; i++){
			printf("%d ", i);
		}
		printf("%d\n", n);
	}
	return 0;
}