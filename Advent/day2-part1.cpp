#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	string code;
	int values[2] = {0, 0};
	unordered_map <char, int> freq;

	while(getline(cin, code)){
		for(int i = 0; i < code.size(); ++i){
			freq[code[i]] += 1;
		}
		
		bool twos = false;
		bool threes = false;

		for(auto it = freq.begin(); it != freq.end(); ++it){
			if(it->second == 2 && twos == false){
				values[0] += 1;
				twos = true;
			}
			if(it->second == 3 && threes == false){
				values[1] += 1;
				threes = true;
			}
			if(twos == true && threes == true) break;
		}
		freq.clear();
	}

	cout << values[0]*values[1] << endl;
	return 0;
}