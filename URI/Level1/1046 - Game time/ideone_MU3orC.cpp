#include <iostream>

int main() {
	int a, b, aux; 
	
	std::cin >> a >> b;
	
	if(a >= b){
		aux = 24 - (a - b);
	}else{
		aux = (b - a);
	}
	
	
	std::cout << "O JOGO DUROU " << aux << " HORA(S)\n";
	return 0;
}