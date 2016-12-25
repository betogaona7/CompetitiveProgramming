#include <stdio.h>
#include <math.h>


int main() {
	int t, a, b;
	double g1, g2;
	double p1, p2;
	bool dec = false;
	
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %lf %lf", &a, &b, &g1, &g2);
		
		int i = 0;
		while(b >= a){
			p1 = (g1 * a)/100;
			p2 = (g2 * b)/100;
			a += p1;
			b += p2;
			i += 1;
			if(i > 100){
				dec = true;
				break;
			}
		}
		if(dec){
			printf("Mais de 1 seculo.\n");
		}else{
			printf("%d anos.\n", i);
		}
		i = 0;
		dec = false;
	}
	return 0;
}