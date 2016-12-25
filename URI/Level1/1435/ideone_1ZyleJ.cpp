#include <stdio.h>

int main(){
    int n, k, m, p, q, nl, np;

    while (scanf("%d", &n), n != 0){
        k = n % 2;
        m = n / 2;

        nl = 1;
        q = n;

        for (int i = 1; i <= n; i++){
            np = 1;
            p = 0;

            for (int j = 0; j < n; j++){

                if (j == 0){
                	printf(" ");
                }else{
                	printf(" ");
                }
                
                if (p == 0 && np != nl){
                    if (np < 10){
                    	printf(" ");
                    }
                    printf("%d", np);
                    np++;
                } else if (np == nl && p < q){
                    if (nl < 10){
                    	printf(" ");	
                    }
                    printf("%d", nl);
                    p++;
                } else {
                    np--;
                    if (np < 10){
                    	printf(" ");
                    }
                    printf("%d", np);
                }
            }

            if (i < m){
                nl++;
                q -= 2;
            } else if (i == m && k == 1){
                nl++;
                q = 1;
            } else if (i == m && k == 0){
                q = 2;
            } else {
                q += 2;
                nl--;
            }
			printf("\n");
        }
		printf("\n");
    }
    return 0;
}