#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int players, snakes, rolls, start, ends, result, aux, size_s;
    int cont_players = 1, cont = 0;
    cin >> n;

    while(n--)
    {
        cin >> players >> snakes >> rolls;

        map<int, int> Snakes_postion;

        while (snakes--){
            cin >> start >> ends;

            Snakes_postion[start] = ends;
            Snakes_postion[ends] = start;
        }
        cont = 0;

        while (rolls --){

            cin >> result;

            if(Snakes_postion.find(result + 1) == Snakes_postion.end()){
                cout << "Position of player " << cont_players << " is " <<result + 1 <<"."<<endl;
            }
            else{
                cout << "Position of player " << cont_players <<" is "<< Snakes_postion[result + 1] <<"."<<endl;
            }
        }
        cont_players = 1;
    }
    return 0;
}
