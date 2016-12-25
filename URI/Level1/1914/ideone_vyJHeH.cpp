#include <iostream>
using namespace std;

int main() {
	int n, n1, n2;
	string inf[4];
	cin >> n;
	while(n--){
		cin >> inf[0] >> inf[1] >> inf[2] >> inf[3];
		cin >> n1 >> n2;
		
		if((n1 + n2)%2 == 0){ //par 
			if(inf[1] == "PAR"){
				cout << inf[0] << endl;
			}else{
				cout << inf[2] << endl;
			}
		}else{
			if(inf[1] == "IMPAR"){
				cout << inf[0] << endl;	
			}else{
				cout << inf[2] << endl;
			}
		}
	}
	return 0;
}