#include <iostream>

using namespace std; 
  
void printTwoElements(int arr[], int size) 
{ 
    int i; 
    int repeated = 0, missing = 0;
    for (i = 0; i < size; i++) { 
        if (arr[abs(arr[i]) - 1] > 0) 
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
        else
            repeated = abs(arr[i]);
    } 
  
    for (i = 0; i < size; i++) { 
        if (arr[i] > 0) missing = (i +1);
    } 
    cout << repeated << " " << missing << endl;
} 
  
int main() 
{ 
    int n, size_x;
	cin >> n;
	while(n--){
	    cin >> size_x;
	    int arr[size_x];
	    for(int i = 0; i < size_x; ++i) cin >> arr[i];
        printTwoElements(arr, size_x); 
	}
	return 0;
} 