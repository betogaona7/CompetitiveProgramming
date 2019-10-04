#include <iostream>
#include <vector>

using namespace std;

string diff_by_one(string a, string b){
	string result = "";
	bool one = false;
	for(int i = 0; i < min(a.size(), b.size()); ++i){
		if(a[i] != b[i]){
			if(one == false) one = true;
			else return "";
		}else result += a[i];
	}
	if(one) return result;
	else return "";
}

int main(){
	string val;
	vector <string> words;
	
	while(getline(cin, val)){
		words.push_back(val);
	}
	
	for(int i = 0; i < words.size(); ++i){
		for(int j = i+1; j < words.size(); ++j){
			string a = diff_by_one(words[i], words[j]);
			if(a.size() > 0) {
				cout << a << endl;
				return 0;
			}
		}
	}
	
	return 0;
}