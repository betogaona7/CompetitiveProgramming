#include <stdio.h>
#include <math.h>

using namespace std;

int main(){

    double PI = 3.141592654;
    double a, b, c, angle, aux, temp;

    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        angle = tan((a * PI)/180);
        aux = angle * b;
        temp = aux + c;

        printf("%.2f\n", temp*5);
    }
return 0;
}
