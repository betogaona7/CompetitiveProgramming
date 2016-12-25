#include <iostream>

using namespace std;

int main()
{
    long n, m;
    cin >> n >> m;
    int cont = 0;

    if(n > m){
        cout<< n - m <<endl;
    }else{
        while(m > n){
            if((m%2) == 0){
                m = m/2;
                cont++;
            }else{
                m += 1;
                cont++;
            }
        }
        if(m == n){
            cout<< cont << endl;
        }else{
            cout<< cont + (n - m) << endl;
        }

    }
    return 0;
}
