#include <iostream>
#include <cstdio>


using namespace std;

int InsertionSort(int arr[], int length)
{
    int key = 0;
    int j = 0;
    for(int i = 1; i < length; i++) //array have 5,2,4,6,1,3
    {
        key = arr[i]; //key = 2
        j = i - 1; // j = 0
        while (j >= 0 && arr[j] > key) // array in j = 5,     5 > 2
        {
            arr[j + 1] = arr[j]; //
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return 0;
}

int main()
{
    int n, number, aux, i, comp, cont;
    cin >> n;
    aux = n;
    int saved[n];

    for(int i = 0; i < n; i++){
        cin >> number;
        saved[i] = number;
    }

    InsertionSort(saved, aux);

    comp = saved[0];
    i = 1;
    cont = 1;
    while(1){
        if(i == n + 1) break;
        if(saved[i] == comp){
            cont++;
            i++;
        }else{
            printf("%d aparece %d vez(es)\n", comp, cont);
            comp = saved[i];
            cont = 0;
        }
    }

    return 0;
}
