#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	string p = "LIFE IS NOT A PROBLEM TO BE SOLVED";
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		printf("%c", p[i]);
	}
	printf("\n");
	
	return 0;
}