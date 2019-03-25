#include <iostream>
#include <string>

using namespace std;

int main(){
	string original = "waterbottle";
	string rotation = "erbottlewat";
	
	if(original.size() != rotation.size()){
		cout << "False" << endl;
	}
	
	original += original; 
	char first = rotation[0];
	for(int i = 0; i < original.size(); ++i){
		if(original[i] == first){
			int j = 0;
			while(original[i+j] == rotation[j]){
				++j;
			}
			if(j == rotation.size()){
				cout << "True" << endl;
				return 0;
			}
		}
	}
	
	cout << "False" << endl; 
										 
	return 0;
}