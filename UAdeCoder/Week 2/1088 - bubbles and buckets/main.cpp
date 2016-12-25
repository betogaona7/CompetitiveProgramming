#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;

    while(scanf("%d", &n), n > 0){
        int numbers[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &numbers[i]);
        }

        int cont = 0, total = 0, special_case = 0;

        for(int i = 0; i < n; i++){
            if(numbers[i] > numbers[i+1]){
                total += i;
            }
            else if(i <= n-2){
                special_case += 1;
                break;
            }
        }
        total += (n-1);
        if(special_case == 0){
            if((total%2) == 0){
                cout<<"Carlos"<<endl;
            }else{
                cout<<"Marcelo"<<endl;
            }
        }else{
            /*for(int i = 0; i < n; i++){
                if(numbers[i] > numbers[i+1]){
                    int temp = numbers[i + 1];
                    numbers[i + 1] = numbers[i];
                    numbers[i] = temp;
                    cont += 1;
                    i = 0;
                }
            }*/
            /*bool swapped;
            do{
                swapped = false;
                for(int i = 0; i < n - 1; i++)
                {
                    if(numbers[i] > numbers[i +1])
                    {
                        int temp = numbers[i + 1];
                        numbers[i + 1] = numbers[i];
                        numbers[i] = temp;
                        cont++;
                        swapped = true;
                    }
                }
            }while(swapped == true);*/
            /*int key = 0, j = 0;
            for(int i = 1; i < n; i++){
                key = numbers[i];
                j = i - 1;
                while (j >= 0 && numbers[j] > key){
                    numbers[j + 1] = numbers[j];
                    cont++;
                    j = j - 1;
                }
                numbers[j + 1] = key;
            }*/

            if((aux%2) == 0){
                cout<<"Carlos"<<endl;
            }else{
                cout<<"Marcelo"<<endl;
            }
        }
    }
    return 0;
}
