#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a, b;
    float c;

    scanf("%i %i %f", &a, &b, &c);

    printf("NUMBER = %i\nSALARY = U$ %.2f\n", a, c*b);
    return 0;
}
