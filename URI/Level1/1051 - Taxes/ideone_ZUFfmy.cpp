#include <iostream>
#include <stdio.h>

int main() {
	float salary;
	std::cin >> salary;
	
	if(salary >= 0 && salary <= 2000){
		printf("Isento\n");
	}else if(salary > 2000 && salary <= 3000){
		printf("R$ %.2f\n", (salary-2000)*.08);
	}else if(salary > 3000 && salary <= 4500){
		printf("R$ %.2f\n", (salary-3000)*.18 + (1000*.08));
	}else{
		printf("R$ %.2f\n", (salary-4500)*.28 + (1500*.18) + (1000*.08));
	}
	return 0;
}