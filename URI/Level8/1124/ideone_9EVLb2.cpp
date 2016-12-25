#include <stdio.h>
#include <math.h>

int main() {
	
	int l, c, r1, r2;
	int hipotenusa, length, mayor;
	
	while(scanf("%d %d %d %d", &l, &c, &r1, &r2), l != 0 && c != 0 && r1 != 0 && r2 != 0){
	
	hipotenusa = sqrt(((l*l) + (c*c)));
	r1 *= 2;
	r2 *= 2;
	
	if(r1 >= r2){
		mayor = r1;
	}else{
		mayor = r2;
	}
	
	length = r1 + r2;
	
	if((hipotenusa > length) || (l > length) || (c > length)){
		
		
		if(((l < length) && (r1 == c || r2 == c)) || ((c < length) && (r1 == l || r2 == l))){
			printf("N\n");
		}else{
			if(c >= mayor){
				printf("S\n");
			}else{
				printf("N\n");
			}	
		}
	}else{
		printf("N\n");
	}
	
	}
	
	return 0;
}