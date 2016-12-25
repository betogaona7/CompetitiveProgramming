#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int r, x, y, x2, y2;
    long double d;
    cin >> r >> x >> y >> x2 >> y2;

    d = sqrt((pow((x2 - x),2)) + (pow((y2 - y),2)));

    cout << ceil(d/(2*r)) << endl;


    return 0;
}
