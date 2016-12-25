#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char substring[100], full_string[100];
    cin.getline(substring,100);
    while(cin.getline(full_string, 100)){

        int maximum = 0;

        for(int i = 0; i < strlen(substring); i++){
            for(int j = 0; j < strlen(full_string); j++){
                if(substring[i] == full_string[j]){
                    int cont = 0;
                    for(int k = 0; k+i < strlen(substring), k+j < strlen(full_string); k++){
                        if(substring[k + i] != full_string[k + j]){
                            break;
                        }
                        cont += 1;
                    }
                    if(cont > maximum){
                        maximum = cont;
                    }
                }
            }
        }

        cout<< maximum << endl;
        cin.getline(substring, 100);
    }
    return 0;
}
