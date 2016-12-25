#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> saved1;
    map<int, int> saved2;
    int a, b;

    while(scanf("%d %d", &a, &b), a > 0 && b > 0){

        int ac[a];
        int bc[b];

        for(int i = 0; i < a; i++){
            scanf("%d", &ac[i]);
        }
        for(int j = 0; j < b; j++){
            scanf("%d", &bc[j]);
        }

        int conta = 0, contb = 0;

        for(int i = 0; i < a; i++){
            if(saved2.find(ac[i]) == saved2.end()){
                int aux = ac[i];
                saved2[aux] = 1;
                conta += 1;
            }else{
                ac[i] = 0;
            }
        }
        for(int i = 0; i < b; i++){
            if(saved1.find(bc[i]) == saved1.end()){
                int aux = bc[i];
                saved1[aux] = 1;
                contb += 1;
            }else{
                bc[i] = 0;
            }
        }

        for(int i = 0; i < a; i++){
            if(saved1.find(ac[i]) != saved1.end()){
                contb -=1;
            }
        }
        for(int j = 0; j < b; j++){
            if(saved2.find(bc[j]) != saved2.end()){
                conta -= 1;
            }
        }

        if(conta < contb){
            cout<<conta<< endl;
        }else{
            cout<<contb<< endl;
        }

        saved1.erase(saved1.begin(), saved1.end());
        saved2.erase(saved2.begin(), saved2.end());
    }

    return 0;
}
