#include <stdio.h>

int main() {
	int a = 0, g = 0, d = 0, c;
	while(scanf("%d", &c), c != 4){
		if(c < 4 && c > 0){
			if(c == 1){
				a += 1;
			}else if( c == 2){
				g +=1;
			}else{
				d +=1;
			}
		}
	}
	
	printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n",a,g,d);
	return 0;
}