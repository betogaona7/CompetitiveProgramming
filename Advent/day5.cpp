#include <iostream>
#include <stack>
using namespace std;

int polymer_size(string chain, char c = -1){
	stack <char> polymer;
	for(int i = 0; i < chain.size(); ++i){
		if(!polymer.empty() && abs(chain[i] - polymer.top()) == 32 && toupper(chain[i]) != c){
			polymer.pop();
		}else{
			if(toupper(chain[i]) == c) continue;
			polymer.push(chain[i]);
		}
	}
	return polymer.size();
}


int main() {
	string chain;
	cin >> chain;
	
	// part 1
	cout << polymer_size(chain) << endl;
	
	// part 2
	int min = 100000;
	for(int i = 65; i < 91; ++i){
		int s = polymer_size(chain, i);
		if(s < min){
			min = s;
		}
	}
	cout << min << endl;
	return 0;
}