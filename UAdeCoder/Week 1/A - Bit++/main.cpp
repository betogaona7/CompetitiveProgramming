#include <iostream>

using namespace std;

int main()
{
    int n, X = 0;
    cin >> n;

    while(n--){

        string statement;
        cin >> statement;

        if(statement == "++X" || statement == "X++"){
            X++;
        }
        else{
            X--;
        }
    }
    cout <<X<< endl;
    return 0;
}
