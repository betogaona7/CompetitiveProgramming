#include <iostream>
using namespace std;

int main() {
	int n, v;
	string name;
	
	cin >> n;
	while(n--){
		cin >> name >> v;
		if(name == "Thor" || name == "thor"){
			cout << "Y\n";
		}else{
			cout << "N\n";
		}
	}
	return 0;
}