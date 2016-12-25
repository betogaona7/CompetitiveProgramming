#include <iostream>
#include <bits/stdc++.h>

int main() {
	int code, amount;
	std::map<int, float> articles;
	
	std::cin >> code >> amount ;
	
	articles[1] = 4.00;
	articles[2] = 4.50;
	articles[3] = 5.00;
	articles[4] = 2.00;
	articles[5] = 1.50;
	
	printf("Total: R$ %.2f\n", articles[code]*amount);
	
	return 0;
}