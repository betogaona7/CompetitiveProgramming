#include <iostream>
#include <string>
#include <bitset>

using namespace std;

char hexdigit(int x){
	if(x >= 0 && x < 10){
		return (x + '0');
	} 
	else if (x < 16){
		return (x - 10 + 'a');
	} 
	else{
		return '!';
	}
}

string hex(int x){
	string result;
	while(x > 0){
		result = hexdigit(x % 16) + result; 
		x /= 16;
	}
	return result;
}

string bin(int x){
	char bin[50];
	int cont = 0;
	string result;
	while(x/2 != 0){
		bin[cont] = x%2 + 48;
		x /= 2;
		cont += 1;
	}
	bin[cont] = x%2 + 48;
	for (int i = cont; i >= 0; i--){
		result += bin[i];
	}
	return result;
}

int main() {
	int n, x;
	string type;
	char number[50];
	int ncase = 1;
	cin >> n;
	while(n > 0){
		cin >> number >> type;
		cout << "Case " << ncase <<":\n";
		if (type == "hex"){
			x = strtol(number, 0, 16);
			
			cout << dec << x << " dec\n";
			cout << bin(x) << " bin\n";
		}else if (type == "bin"){
			x = strtol(number, 0, 2);
			
			cout << dec << x << " dec\n";
			cout << hex(x) << " hex\n";
			
		}else if (type == "dec"){
			x = strtol(number, 0, 10);
	
			cout << hex(x) << " hex\n";
			cout << bin(x) << " bin\n";
		}
		cout << "\n";
		n -= 1;
		ncase += 1;
	}
	return 0;
}