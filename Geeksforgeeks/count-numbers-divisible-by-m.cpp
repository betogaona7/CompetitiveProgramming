#include<iostream>
using namespace std;
int main()
 {
	int a, b, m, n;
	cin >> n;
	while(n--){
	    cin >> a >> b >> m;
	    if(a%m == 0) cout << (b/m)-(a/m) +1 << endl;
	    else cout << (b/m) - (a/m) << endl;
	}
	return 0;
}