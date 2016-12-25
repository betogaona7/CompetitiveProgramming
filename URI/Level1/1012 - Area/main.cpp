#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double pi = 3.14159, a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF){

        printf("TRIANGULO: %.3f\n", (a*c)/2);
        printf("CIRCULO: %.3f\n", pi*(pow(c,2)));
        printf("TRAPEZIO: %.3f\n", ((a + b)/2)*c);
        printf("QUADRADO: %.3f\n", b*b);
        printf("RETANGULO: %.3f\n", a*b);

    }

    return 0;
}
