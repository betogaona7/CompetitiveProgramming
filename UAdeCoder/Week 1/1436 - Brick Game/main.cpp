#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int n, players, temp;
    int cont = 1;
    int ages[9];
    cin >> n;

    while(n--){
        scanf("%d", &players);

        for(int i = 0; i < players; i++){
            scanf("%d",&ages[i]);
        }

        temp = players/2;
        cout<<"Case "<< cont++ <<": " <<ages[temp]<<endl;

    }
return 0;
}
