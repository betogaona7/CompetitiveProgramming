#include<iostream>
using namespace std;
int main()
 {
	int n, x;
	cin >> n;
	while(n--){
	    cin >> x;
	    int r = x & 0xaaaaaaaa;
	    cout << r << endl;
	}
	return 0;
}