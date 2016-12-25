#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while(n--)
    {
        string str, char1, char2, char3;
        cin >> str;

        int x, y;

        char1 = str[0];
        char2 = str[2];
        char3 = toupper(str[1]);

        stringstream ssx(char1);
        stringstream ssy(char2);

        ssx >> x;
        ssy >> y;

        if(char3[0] == str[1] && x != y)
            cout << y-x <<endl;
        if(char3[0] != str[1] && x != y)
            cout << x+y << endl;
        if(x == y)
            cout << x*y << endl;

    }
    return 0;
}
