#include <stdio.h>


int main() {
	int n;
	scanf("%d",&n);
	
	for(int i = 0, aux = 1; i < n; i++, aux += 4){
		for(int j = 0, temp = aux; j < 3; j++, temp += 1){
			printf("%d ",temp);
		}
		printf("PUM\n");
	}
	return 0;
}