#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){
	int val;
	vector <int> values;
	unordered_set<int> freq {0};

	while(cin >> val){
		values.push_back(val);
	}

	int i = 0, acc = 0;
	while(true){
		acc += values[i];
		auto it = freq.insert(acc);
		if(!it.second){
			cout << acc << endl;
			break;
		}
		i+=1;
		if( i == values.size()) i = 0;
	}
	return 0;
}