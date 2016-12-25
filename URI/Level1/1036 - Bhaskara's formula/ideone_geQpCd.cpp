#include <iostream>
#include <math.h>
#include <stdio.h>

int main() {
	
	double a, b, c, R1, R2, cond2, cond1;
	
	std::cin >> a >> b >> c;
	
	cond1 = (2*a);
	cond2 = (pow(b,2)) - (4*a*c);
	
	if(cond1 == 0 || cond2 < 0){
		std::cout << "Impossivel calcular\n";
	}else{
		R1 = ((-b) + (sqrt(cond2)))/cond1;
		R2 = ((-b) - (sqrt(cond2)))/cond1;
		printf("R1 = %.5lf\nR2 = %.5lf\n", R1, R2);
	}
	return 0;
}