#include <iostream>

int main() {
	int n, a, total = 0;
	
	while(std::cin >> a){
        std::cin >> n;
        while(n <= 0){ 
        	std::cin >> n;
        }
        for(int i = a; i < a+n; i++){
            total += i;
        }
        std::cout << total << std::endl;
        total = 0;
    }
	return 0;
}