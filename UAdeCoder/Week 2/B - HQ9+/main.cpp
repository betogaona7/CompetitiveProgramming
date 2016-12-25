#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int main() {

    int cont = 0;
    char s[105];
    gets(s);

   for(int i = 0; i < strlen(s); i++){
        if(s[i] =='H' || s[i] =='Q' || s[i] =='9'){
            cout<<"YES"<<endl;
            cont = 1;
            break;
        }
    }

    if(cont == 0){
        cout<<"NO"<<endl;
    }
    return 0;
}
