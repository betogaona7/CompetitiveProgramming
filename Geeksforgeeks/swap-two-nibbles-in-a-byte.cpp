#include<iostream>
using namespace std;
int main()
 {
    int n, x;
    cin >> n;
    while(n--){
        cin >> x;
        cout << ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 ) << endl;
    }
	return 0;
}