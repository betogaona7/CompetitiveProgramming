#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	long double n;
	string temp;
	std::cin >> n;
	
	if(n > 0){
		printf("+%.4LE\n", n);
	}
	else if(n == 0){
		temp = static_cast<std::ostringstream*>(&(std::ostringstream() << n))->str();
		if(temp[0] == '-'){
			printf("-0.0000E+00\n");
		}else{
			printf("0.0000E+00\n");
		}
	}
	else{
		printf("%.4LE\n", n);	
	}
	return 0;
}