#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a[100005];
    int b[100005];
    int c[100005];

    int n;
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++){
           scanf("%d", &a[i]);
		}
		for(int i = 0; i < n - 1; i++){
           scanf("%d", &b[i]);
		}
		for(int i = 0; i < n - 2; i++){
            scanf("%d", &c[i]);
		}

		sort(a, a + n);
		sort(b, b + n - 1);
		sort(c, c + n - 2);

		for(int i = 0; i < n; i++){
            if(a[i] != b[i]) {
				printf("%d\n", a[i]); break;
			}
		}

		for(int i = 0; i < n - 1; i++){
            if(b[i] != c[i]) {
				printf("%d\n", b[i]); break;
			}
		}

	}

    return 0;
}
