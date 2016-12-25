#include <stdio.h>
#include <math.h>
 
int main() {
    int a, b, c;
    float p;
    while(scanf("%d %d %d", &a, &b, &c), a != 0){
         
        p = (((float)a*(float)b)*100.0)/c;
         
        printf("%.0f\n",trunc(sqrt(p)));
    }
    return 0;
}