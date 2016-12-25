#include <iostream>

using namespace std;

int main()
{
    int n, len1, len2;
    string word1, word2;
    string aux = "";
    bool isWord1 = false;

    cin >> n;
    while(n--){
        cin >> word1 >> word2;

        if(word1.length() >= word2.length()){
            isWord1 = true;
        }else{
            len1 = word2.length();
            len2 = word1.length();
            isWord1 = false;
        }

        int len = word1.length() + word2.length();
        int cont = 0;

        for(int i = 0; i < len; i++){
            if(i < len2){
            }
            else{
                if(isWord1 == true){
                    aux += word1[i];
                }else{
                    aux += word2[i];
                }
            }
        }

        cout << aux << endl;
        aux = "";
    }
    return 0;
}
