#include <iostream>
#include<bits/stdc++.h>

int main() {
	std::map<int,std::string> dest;
	int code;
	
	dest[61] = "Brasilia";
	dest[71] = "Salvador";
	dest[11] = "Sao Paulo";
	dest[21] = "Rio de Janeiro";
	dest[32] = "Juiz de Fora";
	dest[19] = "Campinas";
	dest[27] = "Vitoria";
	dest[31] = "Belo Horizonte";
	
	std::cin >> code;
	if(dest.find(code) == dest.end()){
		std::cout << "DDD nao cadastrado\n";
	}else{
		std::cout << dest[code] << "\n";
	}
	return 0;
}