#include <stdio.h>

int main() {
	int tea, test, total = 0;
	scanf("%d", &tea);
	for(int i = 0; i < 5; i++){
		scanf("%d", &test);
		if(test == tea){
			total += 1;
		}
	}
	printf("%d\n", total);
	return 0;
}