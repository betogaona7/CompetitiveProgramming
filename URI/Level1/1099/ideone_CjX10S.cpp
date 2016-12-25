#include <stdio.h>

int main() {
	int n, x, y, i = 0, total = 0;
	scanf("%d", &n);
	int arr[n];
	
	while(i < n){
		scanf("%d %d", &x, &y);
		
		if(x == y){
			total = 0;
		}
		else if(x > y){
			if(y%2 != 0){
				y += 2;
			}else{
				y += 1;
			}
			while(y < x){
				total += y;
				y += 2;
			//	printf("Total: %d\m", total);
			}
		}else{
			if(x%2 != 0){
				x += 2;
			}else{
				x += 1;
			}
			while(x < y){
				total += x;
				x += 2;
			//	printf("Total: %d\m", total);
				
			}
		}
		arr[i] = total;
		i += 1;
		total = 0;
	}
	
	for(int j = 0; j < n; j++){
		printf("%d\n", arr[j]);
	}
	return 0;
}