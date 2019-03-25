#include <iostream> 
#include <string> 
#include <unordered_map> 

using namespace std;

int main(){
	unordered_map <char, int> hashmap;
	
	string s, t;
	getline(cin, s);
	getline(cin, t);
	
	if(s.size() != t.size()){
		cout << "False" << endl;
		return 0;
	}
	
	for(int i = 0; i < s.size(); ++i){
		hashmap[s[i]] += 1;
		hashmap[t[i]] -= 1;
	}
	
	for(auto it = hashmap.begin(); it != hashmap.end(); ++it){
		if(it->second != 0){
			cout << "False" << endl;
			return 0;
		}
	}
	cout << "True" << endl;
	return 0;
}