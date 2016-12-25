#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int n = 1, x, y;
    cin >> n;
    while(n != 0){

        long cor[n*2];
        int cont = 0;
        long double result = 0;
        long double numero;

        for(int i = 0; i < n; i++){
            cin >> x >> y;
            cor[cont] = x;
            cont += 1;
            cor[cont] = y;
            cont += 1;
        }

        for(int i = 0; i < (n*2)-3; i++){
            //cout << "i: " << i << endl;
            //if(i > n){
             //   i = n*2 - 1;
            //}else{
            numero = sqrt(((pow((cor[i+2] - cor[i]),2))+(pow((cor[i+3] - cor[i+1]),2))));
            //numero *= 100;
            //numero = round(numero);
            //numero /= 100;

            result += numero;
            cout <<cor[i+2] << ", " << cor[i] << "  " << cor[i + 3] << ", " << cor[i+1] << " : "<<result << endl;
                //cout << result << endl;
                //cout << "ahora i vale: "<< i + 2 << endl;
            i += 1;
            //}
           /* if(i == (n*2)-4){
                break;
            }*/
        }

        //numero = sqrt(((pow((cor[(n*2)-2] - cor[0]),2))+(pow((cor[(n*2)-1] - cor[1]),2))));
        numero = sqrt(((pow((cor[0] - cor[(n*2)-2]),2))+(pow((cor[1] - cor[(n*2)-1]),2))));
        //numero *= 100;
        //numero = round(numero);
        //numero /= 100;
        result += numero;

        cout <<cor[0] << ", " << cor[(n*2)-2] << "  " << cor[1] << ", " << cor[(n*2)-1] << " : "<<result << endl;
        //cout << result << endl;
        //printf("%.2lf\n.", &result);
        cin >> n;
    }
    return 0;
}
