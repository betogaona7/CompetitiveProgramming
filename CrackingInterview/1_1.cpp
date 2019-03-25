#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	unordered_map <char, int> hashmap;
	
	string test;
	getline(cin, test);
	
	if(test.size() == 0){
		return 0;
	}
	
	for(int i = 0; i < test.size(); ++i){
		if(test[i] != ' '){
			if(hashmap[test[i]] != 1){
				hashmap[test[i]] = 1;
			}else{
				cout << "False"	<<  endl;
				return 0;
			}	
		}
	}
	cout << "True" << endl;
	return 0;
}