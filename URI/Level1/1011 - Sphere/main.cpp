#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double pi = 3.14159;
    int number;

    scanf("%i", &number);

    double total = (4/3.0) * pi *(pow(number,3));
    printf("VOLUME = %.3f\n", total);

    return 0;
}
