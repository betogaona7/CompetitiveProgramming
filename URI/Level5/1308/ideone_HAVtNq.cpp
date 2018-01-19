#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		long int warriors;
		long int rows = 0;
		
		scanf("%ld", &warriors);
		while(warriors >= 0){
			rows += 1;
			warriors -= rows;
		}
		printf("%ld\n", rows-1);
		
	}
	return 0;
}