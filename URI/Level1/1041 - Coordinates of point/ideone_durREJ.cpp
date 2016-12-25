#include <iostream>

int main() {
	float x, y;
	std::cin >> x >> y;
	
	if(x == 0.0 && y == 0.0){
          std::cout << "Origem\n";
    }else if(x == 0.0){
          std::cout << "Eixo Y\n";
    }else if(y == 0.0){
          std::cout << "Eixo X\n";
    }else if(x < 0.0 && y < 0.0){
          std::cout << "Q3\n";
    }else if(x > 0.0 && y < 0.0){
          std::cout << "Q4\n";
    }else if(x > 0.0 && y > 0.0){
          std::cout << "Q1\n";
    }else if(x < 0.0 && y > 0.0){
          std::cout << "Q2\n";
    }
    
	return 0;
}