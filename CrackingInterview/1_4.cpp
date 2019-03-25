#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	string test = "able was i ere i saw elba";
	unordered_map <char, int> hashmap;
	
	for(int i = 0; i < test.size(); ++i){
		if(test[i] != ' '){
			if(hashmap[test[i]] != 0){
				hashmap[test[i]] += 1;
			}else{
				hashmap[test[i]] = 1;
			}
		}
	}
	
	int imp = 0;
	for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
		if((it->second)%2 != 0){
			++imp;
		}
	}
	
	if((test.size()%2) == 0 && imp == 0){
		cout << "True" << endl;
	}else if((test.size()%2) != 0 && imp == 1){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	return 0;
}