#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    if(n2 <= 2){
        cout<<"nova"<<endl;
    }else if(n2 <= 96){
        if(n2 > n1){
            cout<<"crescente"<<endl;
        }else{
            cout<<"minguante"<<endl;
        }
    }else{
        cout<<"cheia"<<endl;
    }
    return 0;
}
