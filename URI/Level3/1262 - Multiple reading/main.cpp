#include <iostream>

using namespace std;

int main()
{
    string sentence;
    int steps;


    // pendiente;
    while((cin >> sentence >> steps)){

        int cont = 0, aux = 0;

        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == 'W'){
                cont += 1;
            }
            else{
                aux += 1;
                /*if(aux == steps){
                    //cont += 1;
                    aux = 0;
                }
                if(sentence[i+1] == 'W'){
                    //cont += 1;
                    aux += 1;
                }*/
            }
        }

        int temp = (aux/steps) + (aux % steps);
        cout<< cont + temp << endl;
    }
    return 0;
}
