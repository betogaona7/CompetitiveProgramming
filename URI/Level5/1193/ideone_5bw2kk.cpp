#include <iostream>
#include <string>
#include <bitset>

using namespace std;

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
			string binary = bitset<8>(x).to_string();
			if (binary.find('1') != string::npos){
				cout << binary.substr(binary.find('1')) << " bin\n";
			}
		}else if (type == "bin"){
			x = strtol(number, 0, 2);
			cout << dec << x << " dec\n";
			cout << hex << x << " hex\n";
		}else if (type == "dec"){
			x = strtol(number, 0, 10);
			
			cout << hex << x << " hex\n";
			
			string binary = bitset<8>(x).to_string();
			if (binary.find('1') != string::npos){
				cout << binary.substr(binary.find('1')) << " bin\n";
			}
		}
		cout << "\n";
		n -= 1;
		ncase += 1;
	}
	return 0;
}