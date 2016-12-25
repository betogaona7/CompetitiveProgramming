#include <stdio.h>
#include <string>

int main() {
	int t = 0, result = 0;
	char str [3];
	
	
	while(t < 6){
		scanf("%3s", &str);
		if(str[0] == 'c'){
			t += 1;
			if(t%2 != 0){
				printf("%d\n", result);
			}
			result = 0;
		}else{
			for(int i = 0, value = 4; i < 3; i++, value=value/2){
				if(str[i] == '*'){
					result += value;
				}
			}
		}
	}
	return 0;
}