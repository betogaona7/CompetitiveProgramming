#include <stdio.h>

int main() {
	int fh, n, i=0, r = 0;
	
	scanf("%d %d", &fh, &n);
	int ph[n];
	int aux = n;
	
	while(n--){
		scanf("%d", &ph[i]);
		i += 1;
	}
	
	for(int i = 0; i < aux-1; i++){
		if(ph[i] >= ph[i+1]){
			if((ph[i]-ph[i+1]) > fh){
				r += 1;
			}
		}else{
			if((ph[i+1]-ph[i]) > fh){
				r += 1;
			}
		}
	}
	
	if(r > 0){
		printf("GAME OVER\n");
	}else{
		printf("YOU WIN\n");
	}
	return 0;
}