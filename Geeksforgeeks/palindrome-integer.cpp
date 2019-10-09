#include<iostream>
using namespace std;
int main()
 {
	int n;
	cin >> n;
	while(n--){
	    int x; 
	    cin >> x;
	    int sum = 0, tmp = x;
	    while(x > 0){
	        int r = x%10;
	        sum = (sum*10)+r;
	        x = x/10;
	    }
	    if(sum == tmp) cout << "Yes" << endl;
	    else cout << "No" << endl;
	}
	return 0;
}