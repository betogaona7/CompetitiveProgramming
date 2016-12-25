#include <iostream>
#include <bits/stdc++.h>

using namespace std;

    map<int, int> builds;

int main()
{
    int q, e, number, number2;
    cin >> q >> e;

    for(int i = 0; i < e; i++){
        scanf("%i", &number);
        builds[number] = 0;
    }
    while(q--){
        cin >> number2;
        if(builds.find(number2) == builds.end()){
            cout << 1 << endl;
            builds[number2] = 0;
        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}
