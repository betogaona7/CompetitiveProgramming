#include <stdio.h>
#include <algorithm>
#include <iostream>  

int main() {
	
	int n = 0, t = 0, inicio = 0, final = 0;
	
	while(scanf("%d", &n) != EOF){
		int num[n];
	
		for(int i = 0; i < n; i++){
			scanf("%d", &num[i]);
		}
		
		scanf("%d", &t);
		
		while(t--){
	
			scanf("%d %d", &inicio, &final);
			int tam = (final-inicio) + 1;
			
			int tempo[tam];
			int tem = 0;
			
			if(inicio == final){
				printf("1\n");
			}else{
				
				for(int i = inicio; i <= final; i++){
					
					tempo[tem] = num[inicio-1];
					tem += 1;
					inicio += 1;
					
				}
				
				//---
				std::sort(tempo, tempo + tam);
				
				int cont = 0;
				for(int i = 0; i < tam; i++){
					if(tempo[i+1] != tempo[i]){
						cont += 1;
					}
				}
				printf("%d\n", cont);
			}
		}
	}
	
	
	return 0;
}