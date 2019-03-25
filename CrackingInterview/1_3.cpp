#include <iostream> 
#include <string> 

using namespace std;

int main(){
	string test, modi;
	int total; 
	
	getline(cin, test);
	cin >> total; 
	
	cout << test << " " << total << endl;
	for(int i = 0; i < total; ++i){
		if(test[i] == ' '){
			modi += "%20";
		}else{
			modi += test[i];
		}
	}
	cout << modi << endl;
	return 0;
}