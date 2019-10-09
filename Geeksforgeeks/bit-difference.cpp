#include<iostream>
using namespace std;
int main()
 {
	int n, a, b;
	cin >> n;
	while(n--){
	    cin >> a >> b;
	    int x = a^b;
	    int total = 0;
	    while(x){
	        total += x & 1;
	        n >>= 1;
	    }
	    cout << total << endl;
	    
	}
	return 0;
}