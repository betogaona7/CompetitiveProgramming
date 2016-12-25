#include <stdio.h>


int simplifyingNum (int rn, int rd){
	bool negative = false;
	
	if(rn < 0){
		rn *= -1;
		negative = true;
	}else if (rd < 0){
		rd *= -1;
		negative = true;
	}
	
	if(rn == 1){
		if(negative == true){
			printf("-%d/%d\n", rn, rd);
		}else{
			printf("%d/%d\n", rn, rd);
		}
	}else{
		int num = 2;
		while(rn >= num){
			if((rn%num == 0) && (rd%num == 0)){
				rn /= num;
				rd /= num;
			}else{
				num++;
			}
		}
		if(negative == true){
			printf("-%d/%d\n", rn, rd);
		}else{
			printf("%d/%d\n", rn, rd);
		}
	}
	return 0;
}

int main() {
	int n;
	
	int n1, d1, n2, d2;
	char op;
	
	int rn, rd;
	
	scanf("%d", &n);
	while (n--){
		
		scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
		
		
		switch(op){
			case '+':
				rn = n1*d2+n2*d1;
				rd = d1*d2;
				break;
			case '-':
				rn = n1*d2-n2*d1;
				rd = d1*d2;
				break;
			case '*':
				rn = n1*n2;
				rd = d1*d2;
				break;
			case '/':
				rn = n1*d2;
				rd = n2*d1;
				break;
			default:
				break;
		}
		printf("%d/%d = ", rn, rd);
		simplifyingNum(rn, rd); 
		
	}
	return 0;
}