#include <stdio.h>

int main() {
	
	int i = 0, c = 0, r = 0, s = 0, n, d;
	
	char animal;
	
	scanf("%d", &n);
	
	while(i < n){
		scanf("%d %c", &d, &animal);
		
		if(animal == 'C'){
			c += d;
		}else if(animal == 'R'){
			r += d;
		}else{
			s += d;
		}
		
		i += 1;
	}
	int t = c + r + s;
	float pc = ((float)c*100)/(float)t;
	float pr = ((float)r*100)/(float)t;
	float ps = ((float)s*100)/(float)t;
    
	printf("Total: %d cobaias\n", t);
	printf("Total de coelhos: %d\n", c);
	printf("Total de ratos: %d\n", r);
	printf("Total de sapos: %d\n", s);
	printf("Percentual de coelhos: %.2f %\n", pc);
	printf("Percentual de ratos: %.2f %\n", pr);
	printf("Percentual de sapos: %.2f %\n", ps);
	return 0;
}