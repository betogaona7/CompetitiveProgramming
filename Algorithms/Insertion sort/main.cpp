#include <iostream>

using namespace std;

void displayItems(int carts[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<<carts[i]<<endl;
    }
}

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
    int carts[] = {7,2,4,11,1,3,12,7,23,21,20,22,71,3};
    size_t size = (sizeof(carts) / sizeof(carts[0])); //Save array length

    //Display unsorted array.
    cout<<"Array unsorted"<< endl;
    displayItems(carts, size);

    InsertionSort(carts, size);

    cout<<"\nArray sorted..."<< endl;
    displayItems(carts, size);


    return 0;
}
