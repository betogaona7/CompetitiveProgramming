#include <iostream>

using namespace std;

int main()
{
    long n, iman, aux, cont = 0;
    cin >> n;

    while(n--){
        cin >> iman;

        if(aux != iman){
            cont += 1;
        }
        aux = iman;
    }
    cout<< cont << endl;
    return 0;
}
