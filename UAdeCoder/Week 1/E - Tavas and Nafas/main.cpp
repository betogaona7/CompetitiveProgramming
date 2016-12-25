#include<bits/stdc++.h>


using namespace std;

int main()
{
    map<int, string> Dictionary;

    Dictionary[0] = "zero";
    Dictionary[1] = "one";
    Dictionary[2] = "two";
    Dictionary[3] = "three";
    Dictionary[4] = "four";
    Dictionary[5] = "five";
    Dictionary[6] = "six";
    Dictionary[7] = "seven";
    Dictionary[8] = "eight";
    Dictionary[9] = "nine";
    Dictionary[10] = "ten";
    Dictionary[11] = "eleven";
    Dictionary[12] = "twelve";
    Dictionary[13] = "thirteen";
    Dictionary[14] = "fourteen";
    Dictionary[15] = "fifteen";
    Dictionary[16] = "sixteen";
    Dictionary[17] = "seventeen";
    Dictionary[18] = "eighteen";
    Dictionary[19] = "nineteen";
    Dictionary[20] = "twenty";
    Dictionary[30] = "thirty";
    Dictionary[40] = "forty";
    Dictionary[50] = "fifty";
    Dictionary[60] = "sixty";
    Dictionary[70] = "seventy";
    Dictionary[80] = "eighty";
    Dictionary[90] = "ninety";


    int number;
    cin >> number;

    if(number > 20 && ((number % 10) != 0)){
        cout<<Dictionary[(number / 10)*10]<<"-"<<Dictionary[(number % 10)]<<endl;
    }
    else{
        cout<<Dictionary[number]<<endl;
    }

    return 0;
}
