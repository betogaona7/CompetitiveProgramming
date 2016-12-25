#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, x, y;
    int cont = 0, aux = 1;
    map <int, int> saved;
    cin >> t;

    while(t--){
        cin >> n;
        cin >> m;

        while(m--){
            cin >> x >> y;

            if(n == 3){
                if((x == 1 && y == 3)||(x == 2 && y == 3)){
                    cont++;
                }
            }else if(n == 2){
                if((x == 1 && y == 2)){
                    cont++;
                }
            }

            else if(saved.find(x) == saved.end()){
                if(x == (y-1)){
                    cont++;
                    saved[x] = y;
                }
            }
            /*if(saved[x] == y+1 || saved[y] == x+1){
                //ya existe
            }
            else if((y == (x + 1)) || (x == ( y + 1))){
                saved[x] = y;
                saved[y] = x;
                cont++;
            }*/

        }
        //cout<<"cont: "<< cont << " n: " << n << " cont debe ser: "<< n - 1<< " faltan " << (n-1) - cont << endl;

        if ((cont == (n-1)) || (cont > n)){
            cout<<"Caso # "<< aux <<": un promessa foi Cumprida" << endl;
        }else{
            cout<<"Caso # "<< aux <<": ainda Falta (m) "<< (n-1)-cont <<" estrada (s)"<<endl;
        }

        saved.erase(saved.begin(), saved.end());

        aux++;
        cont = 0;
    }
    return 0;
}
