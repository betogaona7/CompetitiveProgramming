#include <stdio.h>
#include <math.h>


using namespace std;

int main() {
	int D, VF, VG, IW = 12;
	double TF, TG, x;
	while(scanf("%d %d %d", &D, &VF, &VG) == 3 ){
		x = (double) sqrt(((IW*IW)+(D*D)));
		TF = (double) IW/VF;
		TG = (double) x/VG;
		
		if(TG > TF){
			printf("N\n");
		}else{
			printf("S\n");
		}
	}
	return 0;
}