#include <stdio.h>

int main() {
	int n, x, y, total = 0;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &x , &y);
		if(x%2 == 0){
			x += 1;
		}
		for(int i = x, j = 0; j < y; j++, i+= 2){
			total += i;
		}
		printf("%d\n",total);
		total = 0;
	}
	return 0;
}