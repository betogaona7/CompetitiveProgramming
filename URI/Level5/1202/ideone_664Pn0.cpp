#include <iostream>
#include <string> 

using namespace std;

int todecimal(long long n){
	int factor = 1, total = 0;
	while(n != 0){
		total += (n%10)*factor;
		n /= 10;
		factor *= 2;
	}
	return total;
}

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
		long long  binary;
		cin >> binary;
		int decNum = todecimal(binary);
		if(decNum < 7){
			cout << "00" << fibonacci(decNum) << "\n";
		}else if (decNum < 11){
			cout << "0" << fibonacci(decNum) << "\n";
		}else{
			cout << fibonacci(decNum) << "\n";
		}
		n -= 1;
	}
	return 0;
}
