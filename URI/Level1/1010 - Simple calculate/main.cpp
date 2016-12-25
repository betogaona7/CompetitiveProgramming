#include <stdio.h>

using namespace std;

int main()
{
    int a1, b1, a2, b2;
    float c1, c2, total;

    scanf("%i %i %f", &a1, &b1, &c1);
    scanf("%i %i %f", &a2, &b2, &c2);

    total = (c1 * b1) + (c2 * b2);
    printf("VALOR A PAGAR: R$ %.2f\n", total);
    return 0;
}
