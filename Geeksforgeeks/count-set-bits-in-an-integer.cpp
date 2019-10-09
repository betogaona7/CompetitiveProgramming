#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	while(n--){
	    int total = 0;
	    cin >> x;
	    while(x){
	        total += x & 1;
	        x >>= 1;
	    }
	    cout << total << endl;
	}
	return 0;
}