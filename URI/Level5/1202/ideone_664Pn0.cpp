#include <iostream>
#include <string> 

using namespace std;

long long int fibonacci(int n){
	long long int current = 0, previous = 0, after = 1;
	for (int i = 0; i < n; i++){
		current = previous + after;
		previous = after;
		after = current;
	}
	return previous;
}

int main() {
	int n;
	cin >> n;
	while(n  > 0){
		n -= 1;
		string binary;
		cin >> binary;
		long long int n = stoll(binary, 0, 2);
		if(n < 7){
			cout << "00" << fibonacci(n) << "\n";
		}else if (n < 11){
			cout << "0" << fibonacci(n) << "\n";
		}else{
			cout << fibonacci(n) << "\n";
		}
	}
	return 0;
}