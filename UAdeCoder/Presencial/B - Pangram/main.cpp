#include <iostream>

using namespace std;

int main()
{
    string alphabet1 = "abcdefghijklmnopqrstuvwxyz";
    string alphabet2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string word;

    int n;
    cin >> n;

    cin >> word;

    int cont = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < alphabet1.length(); j++){
            if(word[i] == alphabet1[j] || word[i] == alphabet2[j]){
                alphabet1[j] = 0;
                alphabet2[j] = 0;
                cont += 1;
            }
        }
    }
    if(cont == alphabet1.length()){
        cout<<"YES"<< endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
