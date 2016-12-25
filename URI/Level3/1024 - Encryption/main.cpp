#include <iostream>

using namespace std;

int main()
{
    int n;
    string sentence;
    string aux = "";
    cin >> n;

    cin.get();

    while(n--){
        getline(cin, sentence);

        for(int i = 0; i < sentence.length(); i++){
            if(isalpha(sentence[i])){
                sentence[i] = sentence[i] + 3;
            }
            if(i < (sentence.length() + 1)/2){
                sentence[i] = sentence[i] - 1;
            }
        }
        int cont = sentence.length() - 1;
        aux = sentence;

        for(int i = 0; i < sentence.length(); i++){
            sentence[i] = aux[cont];
            cont -= 1;
        }

        cout << sentence << endl;

    }
    return 0;
}
