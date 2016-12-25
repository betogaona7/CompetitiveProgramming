#include <stdio.h>

int main() {
	int i = 0, pos = 0;
	float number;
	
	while(i < 6){
		scanf("%f", &number);
		if(number > 0){
			pos += 1;
		}
		i += 1;
	}
	printf("%d valores positivos\n", pos);
	return 0;
}