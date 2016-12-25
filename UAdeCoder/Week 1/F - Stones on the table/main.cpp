#include <iostream>

using namespace std;

int main()
{
    char a,b;
    int cont=0;

    int stones;
    cin>>stones;

    cin>>a;

    for(int i = 1; i < stones; i++){

       cin>>b;

       if(b == a){
        cont++;
       }
       else{
        a = b;
       }
    }
    cout << cont <<endl;

    return 0;
}
