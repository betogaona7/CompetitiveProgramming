#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;


void BubbleSort(int arr[][2], int length)
{
    bool swapped;
    do
    {
        swapped = false;
        for(int i = 0; i < length-1; i++)
        {
            if(arr[i][0] > arr[i+1][0])
            {
                int temp = arr[i+1][0];
                arr[i + 1][0] = arr[i][0];
                arr[i][0] = temp;
                
                int temp2 = arr[i+1][1];
                arr[i + 1][1] = arr[i][1];
                arr[i][1] = temp2;
                
                
                swapped = true;
            }
        }
    }while(swapped == true);
}

int main() {
	
	int n, res, cons;
	int city = 1;
	
	double average = 0;
	
	while(scanf("%d", &n), n != 0){
		
		map <int, int> result;
		int copy[n][2];
		
		double sumRes = 0, sumCons = 0;
		int auxRes = 0, auxCon = 0, cont = 0, index = 0;
		int total = n, eliminado = 0, consumo = 0;
		
		int temp[n];
		
		printf("Cidade # %d:\n", city);
		city += 1;
		
		while(n--){
			scanf("%d %d", &res, &cons);
			
			temp[cont] = cons;
			cont += 1;
			
			consumo = floor(cons/res);
			
			/*if(result.find((cons/res)) == result.end()){
				result[(cons/res)] = res;
			}else{
				auxRes = result[(cons/res)] + res;
				auxCon = temp[index-1] + cons;
				result.erase((cons/res));
				result[(auxCon/auxRes)] = auxRes;
				
				eliminado += 1;
			}*/
			if(result.find(consumo) == result.end()){
				result[(consumo)] = res;
			}else{
				auxRes = result[(consumo)] + res;
				auxCon = temp[index-1] + cons;
				result.erase(consumo);
				
				consumo = floor(cons/res);
				result[consumo] = auxRes;
				
				eliminado += 1;
			}
			
			sumRes += res;
			sumCons += cons;
			index += 1;
		}
		
		map<int,int>::iterator it;
		
		
		int conta = 0;
		for (it=result.begin(); it!=result.end(); ++it){
			//cout << it->first << "-" << it->second << ' ';
			copy[conta][0] = it->first;
			copy[conta][1] = it->second;
			
			//printf("Array: %d %d\n", copy[conta][0], copy[conta][1]);
			
			conta += 1;
		}
	
		
		BubbleSort(copy, total-eliminado);
		
		for(int i = 0; i < (total-eliminado); i++){
			printf("%d-%d ", copy[i][1], copy[i][0]);
		}
		
		average = sumCons/sumRes;
		printf("\nConsumo medio: %.2f m3.\n\n", trunc(100*average)/100);
	}
	// your code goes here
	return 0;
}