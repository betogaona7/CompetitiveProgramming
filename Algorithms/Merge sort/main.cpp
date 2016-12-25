#include <iostream>
#include <algorithm>


using namespace std;

void DisplayArray(int carts[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout<< carts[i] << endl;
    }
}

void Merge(int arr[], int first,int middle,int last)
{
    // left[10], right[10];

    int n1, n2, i, j, k;
    n1 = middle - first + 1;
    n2 = last - middle;

    int left[n1 + 1], right[n2 + 1];

    for(i = 0; i < n1; i++)
    {
        left[i] = arr[first + i];
    }
    for(j = 0; j < n2; j++)
    {
        right[j] = arr[middle + j + 1];
    }
    //Add sentinel value;
    left[i] = 99999;
    right[j] = 99999;

    i = 0;
    j = 0;

    for(k = first; k <= last; k++)
    {
        if(left[i] <= right[j])
        {
            arr[k] = left[i++];
        }
        else
        {
            arr[k] = right[j++];
        }
    }
    //return 0;
}

void MergeSort(int arr[], int first, int last)
{
    int middle;
    if(first < last)
    {
        middle = (first + last)/2;
        MergeSort(arr, first, middle);
        MergeSort(arr, middle + 1, last);
        Merge(arr, first, middle, last);
    }
    //return 0;
}


int main()
{
    int carts[] = {2,4,5,7,1,2,3,6, 1};
    size_t size = (sizeof(carts)/sizeof(carts[0]));

    cout<<"Unsorted array..." << endl;
    DisplayArray(carts, size);

    MergeSort(carts, 0, size - 1);

    cout<<"\nArray sorted..."<< endl;
    DisplayArray(carts, size);

    return 0;
}
