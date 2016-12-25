#include <stdio.h>

int main() {
	int n, p = 0;
	long int r, f;
	float s, may = 8;
	
	scanf("%d", &n);
	while(n--){
		scanf("%ld %f", &r, &s);
		if(s >= may){
			p += 1;
			may = s;
			f = r;
		}
	}
	
	if(p == 0){
		printf("Minimum note not reached\n");
	}else{
		printf("%ld\n", f);
	}
	return 0;
}