#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		long long int warriors, row;
		
		scanf("%lld", &warriors);
		row = (-1 + sqrt(1+(warriors*8)))/2;
		printf("%lld\n", row);
	}
	return 0;
}