#include <cstdio>
#include <iostream>

using namespace std;

int n, k;

long long factorial(int f){

    int result = n - (f * k);
    if (result >= 1){
        return result * factorial(f + 1);
    }
    return 1;
}

int main(){

    int t;
    string string_k;

    cin >> t;

    while (t--){

        cin >> n >> string_k;
        k = string_k.length();

        cout << factorial(0) << endl;
    }
    return 0;
}
