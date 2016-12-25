#include <iostream>
#include <stdio.h>

int main() {
	
	float salary;
	std::cin >> salary;
	
	
	if(salary >= 0 && salary <= 400){
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 15 %\n", (salary*.15)+salary, (salary*.15));
	}else if(salary > 400 && salary <= 800){
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 12 %\n", (salary*.12)+salary, (salary*.12));
	}else if(salary > 800 && salary <= 1200){
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 10 %\n", (salary*.10)+salary, (salary*.10));
	}else if(salary > 1200 && salary <= 2000){
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 7 %\n", (salary*.07)+salary, (salary*.07));
	}else{
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 4 %\n", (salary*.04)+salary, (salary*.04));
	}
	
	return 0;
}