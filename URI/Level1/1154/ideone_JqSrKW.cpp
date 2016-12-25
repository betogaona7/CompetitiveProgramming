#include <stdio.h>

int main() {
	int a, total = 0, i = 0;
	while(scanf("%d", &a), a > 0){
		total += a;
		i += 1;
	}
	printf("%.2f", (float)total/i);
	return 0;
}