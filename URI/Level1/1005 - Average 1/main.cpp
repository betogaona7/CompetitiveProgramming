#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double a, b, media;
    cin >> a;
    cin >> b;

    media = ((a*3.5)+(b*7.5))/(3.5 + 7.5);
    printf("MEDIA = %.5f\n", media);

    return 0;
}
