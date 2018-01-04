#include <iostream>
#include <string>

using namespace std;

int factorial(int n){
	int result = 1;
	for(int i = n; i > 0; i--){
		result *= i;
	}
	return result;
}

int main() {
	string n;
	while(cin >> n){
		if(n == "0"){
			break;
		}
		
		int fac = n.length();
		int res = 0;
		for(int i = 0; i < n.length(); i++){
			res += (n[i]-'0') * factorial(fac);
			fac -= 1;
		}
		cout << res << "\n";
	}
	return 0;
}