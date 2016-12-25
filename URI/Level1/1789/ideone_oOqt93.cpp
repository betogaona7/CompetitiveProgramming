#include <stdio.h>
 
int main() {
    int n, t, type = 0, temp = 0;
    while(scanf("%d", &n) != EOF){
        while(n--){
            scanf("%d", &t);
            if(t < 10){
                type = 1;
            }else if(t >= 10 && t < 20){
                type = 2;
            }else{
                type = 3;
            }
            if(type > temp){
                temp = type;
            }
        }
        printf("%d\n", temp);
        temp = 0;
    }
    return 0;
}