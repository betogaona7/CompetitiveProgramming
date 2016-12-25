#include <iostream>

using namespace std;

int main()
{

    int n, enter, exit, tram, capacity;
    cin >> n;

    tram = capacity = 0;
    for(int i = 0; i < n; i++){

        cin >> exit >> enter;

        tram -= exit;
        tram += enter;

        if(tram > capacity){
            capacity = tram;
        }
    }

    cout << capacity << endl;
    return 0;
}
