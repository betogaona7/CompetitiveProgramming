#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	double a, b, result;
	cin >> a >> b;
	result = ((b-a)*100)/a;
	
	printf("%.2f%\n", result);
	return 0;
}