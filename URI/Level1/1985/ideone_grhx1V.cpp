#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
	int n,c,p;
	float total;
	map<int, float>table;
	
	table[1001] = 1.50;
	table[1002] = 2.50;
	table[1003] = 3.50;
	table[1004] = 4.50;
	table[1005] = 5.50;
	
	scanf("%d", &n);
	
	while(n--){
		scanf("%d %d", &c, &p);
		total += table[c] * p;
	}
	
	printf("%.2f\n", total);
	
	return 0;
}