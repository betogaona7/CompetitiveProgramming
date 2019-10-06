#include <iostream>
#include <stack>
using namespace std;

int main() {
	string chain;
	cin >> chain;
	
	stack <char> polymer; 
	
	for(int i = 0; i < chain.size(); ++i){
		if(!polymer.empty() && abs(chain[i] - polymer.top()) == 32){
			polymer.pop();
		}else{
			polymer.push(chain[i]);
		}
	}
	
	cout << polymer.size() << endl;
	
	
	return 0;
}