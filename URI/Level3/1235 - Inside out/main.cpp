#include <iostream>

using namespace std;

int main(){

    string sentence, aux = "";
    int n, half, ends;

    cin >> n;
    cin.get();
    while(n--){
        getline(cin, sentence);

        aux = sentence;

        int half = sentence.length()/2;
        int ends = sentence.length()-1;

        for(int i = 0; i < sentence.length(); i++){
            if(i < sentence.length()/2){
                sentence[i] = aux[half - 1];
                half -= 1;
            }else{
                sentence[i] = aux[ends];
                ends -= 1;
            }
        }

        cout<< sentence << endl;

    }
    return 0;
}
