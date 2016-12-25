#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int row, aux;
    long long suma, total;
    cin >> row;

    long long matriz[21];
    long long matriz2[21];

    for(int i = 0; i < 21; i++){
        if(i > 1){
            matriz[i] = 0;
        }else{
            matriz[i] = 1;
        }
        matriz2[i] = 0;
    }

    if(row == 0){
        cout << 1 << endl;
    }else if (row == 1){
        cout << 3 << endl;
    }else{
        row = row - 1;
        while(row--){
            for(int i = 0; i < 21; i++){
                if(i == 0){
                    matriz2[0] = (matriz[1] * 2) + matriz[0];
                }
                else if(i == 19){
                    suma = 0;
                    aux = i - 1;
                    for(int j = aux; j <= i; j++){
                        suma += matriz[j];
                    }
                    matriz2[i] = suma;
                }
                else if(i == 20){
                    matriz2[i] = matriz[i-1];
                }
                else{
                    suma = 0;
                    aux = i - 1;
                    for(int j = aux; j <= (i+1); j++){
                        suma += matriz[j];
                    }
                    matriz2[i] = suma;
                }
            }

            total = 0;
            for(int i = 0; i < 21; i++){
                matriz[i] = matriz2[i];
                if(i != 0){
                    total += matriz2[i];
                }
            }
        }
        cout <<(total*2 + matriz2[0]) << endl;
    }

    return 0;
}
