#include <iostream>

int main() {
	
	double a, b, c, A, B, C;
	
	std::cin >> a >> b >> c;
	
	A = a*a;
	B = b*b;
	C = c*c;
	
	if(a >= (b+c) || b >= (a+c) || c >= (a+b)){
        std::cout << "NAO FORMA TRIANGULO\n";
	}
    else if(A == (B + C) || B == (A + C) || C == (A + B)){
    	std::cout << "TRIANGULO RETANGULO\n";
    }
    else if(A > (B + C) || B > (A + C) || C > (A + B)){
    	std::cout << "TRIANGULO OBTUSANGULO\n";
    }
    else if(A < (B + C) || B < (A + C) || C < (A + B)){
    	std::cout << "TRIANGULO ACUTANGULO\n";
    }
           
           
           
    if(a == b && a == c){
    	std::cout << "TRIANGULO EQUILATERO\n";
    }
    if((a == b && a != c)  || (a == c && a != b) || (b == c && b != a)){
    	std::cout << "TRIANGULO ISOSCELES\n";
    }
	
	return 0;
}