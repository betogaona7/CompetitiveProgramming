#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long factorial(long long number, long long total){

    long long value = 0;
    value += total;

    if(number == 1){
        return value;
    }else{
        value *= number;
        factorial(number - 1, value);
    }
}

int main()
{
    string sentence = "";
    map <int, int> saved;

    cin >> sentence;

    while(sentence != "0"){
        int number = sentence.length();

        int cont = 0;
        for(int i = 0; i < sentence.length(); i++){
            if(saved.find(sentence[i]) == saved.end()){
                saved[sentence[i]] = 0;
            }else{
                cont += 1;
            }
        }

        if(cont > 0){
            long long n = factorial(number,1);
            long long r = factorial(cont, 1);
            long long s = 1;
            if((number - cont) != 0){
                s = factorial((number - cont), 1);
            }

            cout<< n/(r*s) << endl;

        }else{
            cout<< factorial(number, 1) << endl;
        }
        saved.erase(saved.begin(), saved.end());

        cin >> sentence;
    }

    return 0;
}
