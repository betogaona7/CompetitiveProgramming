#include <iostream>

using namespace std;

int survivor(int p, int s){
    if(p == 1){
        return 1;
    }
    return ((survivor(p - 1, s) + s - 1) % p) + 1;
}

int main()
{
    int n, persons, steps, cont = 1;
    cin >> n;

    while(n--){
        cin >> persons >> steps;
        cout << "Case " << cont << ": " << survivor(persons, steps) << endl;
        cont += 1;
    }
    return 0;
}
