#include <iostream>
using namespace std;

int main() {
	int number;
	int values[] = {100, 50, 20, 10, 5, 2, 1};
	cin >> number;
	
	cout << number << endl;
	for(int i = 0; i < 7; i++){
		cout<<number/values[i] << " nota(s) de R$ "<<values[i]<< ",00"<< endl;
		number = number%values[i];
	}
	return 0;
}