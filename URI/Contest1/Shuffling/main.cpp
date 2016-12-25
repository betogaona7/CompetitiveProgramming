#include <iostream>

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

    cin >> sentence;

    while(sentence != "0"){
        int number = sentence.length();

        cout << factorial(number, 1) << endl;

        cin >> sentence;
    }

    return 0;
}
