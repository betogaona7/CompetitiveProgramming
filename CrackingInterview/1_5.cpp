#include <iostream>
#include <string> 
#include <unordered_map>

using namespace std;

int main(){
	unordered_map <char, int> hashmap; 
	int ops = 0;
	
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout << a << " - " << b << endl;
	if(a.size() != b.size()){
		if(abs(int(a.size()-b.size())) == 1){
			++ops;
		}else{
			cout << "False" << endl;
			return 0;
		}
	}
	
	for(int i = 0; i < a.size(); ++i){
		hashmap[a[i]] += 1;
	}
	
	for(int i = 0; i < b.size(); ++i){
		if(hashmap[b[i]] == 0){
			++ops;
		}else{
			hashmap[b[i]] -= 1;
		}
	}
	
	for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
		if(it->second < 0){
			++ops;
		}
	}
	if(ops <= 1){
		cout << "True" << endl;
	}else{
		cout << "False" << endl;
	}
	return 0;
}