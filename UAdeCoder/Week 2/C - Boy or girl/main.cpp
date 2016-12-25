#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    map<char, int> saved;

    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(saved.find(str[i]) == saved.end()){
            char aux = str[i];
            saved[aux] = 1;
        }
    }

    if((saved.size() % 2) == 0){
        cout<<"CHAT WITH HER!"<<endl;
    }else{
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}
