#include <stdio.h>

int main(){
    int c,n;
    float suma,s;

    scanf("%d",&c);
    while(c > 0){
            scanf("%d",&n);
            suma = 0;
            s = 0;
            int num[n];
            for(int i = 0; i < n; i++){
                    scanf("%d",&num[i]);
                    suma+=num[i];
            }
            suma /= n;
            for(int i = 0; i < n; i++){
                    if(num[i] > suma) s++;
            }
            printf("%.3f%c\n",s/n*100.000,'%');
            c--;
    }
    return 0;
}
