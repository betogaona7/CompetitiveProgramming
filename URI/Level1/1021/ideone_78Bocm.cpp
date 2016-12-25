#include <stdio.h>
#include <math.h>

int main() {
	float n;
	float tempo = 0;
	scanf("%f", &n);
	
	float notas[6] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00};
	float moedas[6] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01}; 
	
	printf("NOTAS:\n");
	for(int i = 0; i < 6; i++){
		tempo =  floor(n/notas[i]);
		printf("%.0f nota(s) de R$ %.2f\n", tempo, notas[i]);
		n -= tempo*notas[i];
	}
	printf("MOEDAS:\n");
	for(int i = 0; i < 5; i++){
		tempo = floor(n/moedas[i]);
		printf("%.0f moeda(s) de R$ %.2f\n", tempo, moedas[i]);
		n -= tempo*moedas[i];
	}
//	printf("Resultado %f Modulo %f\n", n/moedas[5], n);
	
	
	tempo = round(n/moedas[5]);
	printf("%.0f moeda(s) de R$ %.2f\n", tempo, moedas[5]);
	
	return 0;
}