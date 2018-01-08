#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int n, squares;
	unsigned long long int result;
	scanf("%d", &n);
	while(n > 0){
		scanf("%d", &squares);
		result = ((pow(2, squares)-1)/12)/1000;
		printf("%llu kg\n", result);
		
		n -= 1;
	}
	return 0;
}