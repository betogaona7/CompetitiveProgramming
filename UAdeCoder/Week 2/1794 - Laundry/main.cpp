#include <iostream>

using namespace std;

int main()
{
    int n;
    int cont = 0;
    int LA, LB, SA, SB;

    cin >> n;
    cin >> LA >> LB;
    if(LA <= n && n <= LB){
        cont += 1;
    }
    cin >> SA >> SB;
    if(SA <= n && n <= SB){
        cont += 1;
    }

    if(cont == 2){
        cout<<"possivel"<<endl;
    }else{
        cout<<"impossivel"<<endl;
    }
    return 0;
}
