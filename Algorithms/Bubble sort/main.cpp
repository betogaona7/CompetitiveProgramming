#include <iostream>

using namespace std;

void DisplayArray(int arr[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<< arr[i]<<endl;
    }
}

void BubbleSort(int arr[], int length)
{
    bool swapped;
    do
    {
        swapped = false;
        for(int i = 0; i < length - 1; i++)
        {
            if(arr[i] > arr[i +1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
    }while(swapped == true);
}
int main()
{
    int carts[] = {5,62,23,23,43,12,53,1,7};
    size_t size = (sizeof(carts) / sizeof(carts[carts[0]]));

    cout<<"Unsorted array..."<<endl;
    DisplayArray(carts, size);

    BubbleSort(carts, size);

    cout<<"Sorted array..."<<endl;
    DisplayArray(carts, size);

    return 0;
}
