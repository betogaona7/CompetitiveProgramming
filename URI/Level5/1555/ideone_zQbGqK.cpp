#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, x, y, rafa, beto, carlos;
    
    scanf("%d", &n);
    while(n > 0){
    	scanf("%d %d", &x, &y);
    	
    	rafa = (3*x) * (3*x) + y*y;
	beto = 2*(x*x) + (5*y) * (5*y);
	carlos = -100*x + y*y*y;
    
	if(rafa > beto && rafa > carlos){
		printf("Rafael ganhou\n");
	}else if(beto > rafa && beto > carlos){
		printf("Beto ganhou\n");
	}else if(carlos > rafa && carlos > beto){
		printf("Carlos ganhou\n");
	}
    	n -= 1; 
    }
    return 0;
}