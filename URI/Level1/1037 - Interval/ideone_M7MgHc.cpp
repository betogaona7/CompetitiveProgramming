#include <iostream>

int main() {
	float a;
	
	std::cin >> a;
	
	if(a < 0 || a > 100){
		std::cout<<"Fora de intervalo\n";
	}else{
		if(a <= 25){
			std::cout<<"Intervalo [0,25]\n";
		}else if (a <= 50){
			std::cout<<"Intervalo (25,50]\n";
		}else if (a <= 75){
			std::cout<<"Intervalo (50,75]\n";
		}else if (a <= 100){
			std::cout<<"Intervalo (75,100]\n";
		}
	}
	return 0;
}