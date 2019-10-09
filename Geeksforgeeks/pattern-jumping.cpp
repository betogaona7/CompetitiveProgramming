#include<iostream>
#include<math.h>

using namespace std;
int main()
 {
    int n, x;
	cin >> n;
	while(n--){
	    cin >> x;
	    if(x == 1 || x == 2) cout << "True" << endl;
	    else if(ceil(log2(x)) == floor(log2(x))) cout << "True" << endl;
	    else cout << "False" << endl;
	}
	return 0;
}