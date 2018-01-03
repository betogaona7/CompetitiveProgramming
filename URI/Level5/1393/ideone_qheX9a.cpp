#include <stdio.h>

using namespace std;

int main() {
	int tiles;
	while(scanf("%d", &tiles), tiles != 0){
		int ss[tiles + 1];
		ss[tiles] = 1; 
		ss[tiles-1] = 1;
		
		for(int i = tiles-2; i >= 0; --i){
			ss[i] = ss[i+1] + ss[i+2];
		}
		printf("%d\n", ss[0]);
	}
	return 0;
}