#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    double R, area;
    double pi = 3.14159;

    cin >> R;

    area = pi * (pow(R,2));
    printf("A=%.4f\n", area);

    return 0;
}
