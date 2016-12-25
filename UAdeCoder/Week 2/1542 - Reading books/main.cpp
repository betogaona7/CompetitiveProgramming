#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int q, d, p,

pages;

int main()
{
    while(scanf("%d", &q), q != 0){
        scanf("%d %d", &d, &p);
        pages = trunc((double)(q * d) / -(q - p) * p);

        if(pages == 1){
            printf("1 pagina\n");
        }
        else{
            cout << pages << " paginas" << endl;
        }

    }
    return 0;
}
