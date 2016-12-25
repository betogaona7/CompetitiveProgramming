#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string name;
    double a, b, total;

    cin >> name >> a >> b;
    total = (b*.15)+ a;

    printf("TOTAL = R$ %.2f\n", total);

    return 0;
}
