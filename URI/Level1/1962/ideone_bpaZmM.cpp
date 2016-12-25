#include <stdio.h>

int main() {
	int n;
	long long int year;
	scanf("%d", &n);
	
	while(n--){
		scanf("%lld", &year);
		if(year >= 0 && year <= 2014){
			printf("%lld D.C.\n", 2015-year);
		}else if(year > 2014){
			printf("%lld A.C.\n", (year-2015)+1);
		}else{
			printf("%lld D.C.\n", 2015+(year*(-1)));
		}
	}
	return 0;
}