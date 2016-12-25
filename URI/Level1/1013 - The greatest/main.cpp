#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, c, temp;
	cin >> a >> b >> c;
	
	temp = (a+b+(abs(a-b)))/ 2;
	temp = (temp+c+(abs(temp - c)))/2;
	
	cout << temp << " eh o maior" << endl; 
	
	return 0;
}