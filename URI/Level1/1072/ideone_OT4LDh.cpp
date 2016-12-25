#include <stdio.h>

int main() {
	int n, in = 0, out = 0, num;
	scanf("%d", &n);
	
	while(n--){
		scanf("%d", &num);
		if(num >= 10 && num <= 20){
			in += 1;
		}else{
			out += 1;
		}
	}
	printf("%d in\n%d out\n", in, out);
	return 0;
}