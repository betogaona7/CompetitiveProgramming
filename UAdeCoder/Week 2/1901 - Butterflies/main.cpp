#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, aux, aux2, value, x, y;
    int cont = 0;
    map<int, int> saved;

    cin >> n;
    aux2 = aux = n;

    int butterflies [n][n];

    while(n--){
        for(int i = 0; i < aux; i++){
            scanf("%d", &value);
            butterflies[cont][i] =  value;
        }
        cont++;
    }

    aux2 = aux2 * 2;
    while(aux2--){
        cin >> x >> y;
        int type = butterflies[x - 1][y - 1];
        if(saved.find(type) == saved.end()){
            saved[type] = 1;
        }
    }

    cout<< saved.size() << endl;
    return 0;
}
