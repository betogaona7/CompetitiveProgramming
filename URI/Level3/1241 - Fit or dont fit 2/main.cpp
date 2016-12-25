#include <iostream>

using namespace std;

int main()
{
    int n;
    string a, b;
    cin >> n;

    while(n--){
        cin >> a >> b;

        int aux = 0;

        for(int j = b.length(), k = a.length(); j >= 0; j--, k--){
            if(a[k] == b[j]){
                aux += 1;
            }else{
                break;
            }
        }

        if(aux == b.length() + 1){
            cout<<"encaixa" << endl;
        }
        else{
            cout<<"nao encaixa"<< endl;
        }
    }
    return 0;
}
