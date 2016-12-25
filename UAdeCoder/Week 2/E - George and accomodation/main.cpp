#include <iostream>

using namespace std;

int main()
{
    int n, p, q;
    int cont = 0;
    cin >> n;

    while(n--){
        cin >> p >> q;
        if((q-p) >= 2){
           cont++;
        }
    }
    cout<< cont << endl;
    return 0;
}
