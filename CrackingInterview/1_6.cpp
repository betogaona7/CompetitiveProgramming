#include <iostream>
#include <string>
#include <vector> 

using namespace std;

int main(){
	
	string test = "aabcccccaaa";
	string result = "";
		
	if(test.size() == 0){
		return 0;
	}
	
	char c = test[0];
	int cont = 0;
	for(int i = 0; i < test.size(); ++i){
		if(test[i] == c){
			++cont;
		}else{
			result += test[i-1] + to_string(cont);
			cont = 1;
			c = test[i];
		}
	}
	result += test[test.size()-1] + to_string(cont); // Add the last one
	
	if(result.size() > test.size()){
		cout << test << endl;
	}else{
		cout << result << endl;
	}
	
	return 0;
}