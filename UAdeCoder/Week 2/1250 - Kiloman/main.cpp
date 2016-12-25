#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, s, hit = 0;
    string str;

    cin >> n;

    while(n--){
        cin >> s;
        int ss[s];
        for(int i = 0; i < s; i++){
            scanf("%d", &ss[i]);
        }

        cin >> str;

        for(int i = 0; i < str.length(); i++){
            if((str[i] == 'J' && ss[i] > 2) || (str[i] == 'S' && ss[i] <= 2)){
                hit += 1;
            }
        }
        cout <<hit<<endl;
        hit = 0;
    }
    return 0;
}
