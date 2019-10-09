#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, size_a, size_b;
    cin >> n;
    while(n--){
        cin >> size_a >> size_b;
        
        vector <int> a(size_a, 0);
        vector <int> b(size_b, 0);
        vector <int> t(size_a+size_b-1, 0);
        
        for(int i = 0; i < size_a; ++i) cin >> a[i];
        for(int i = 0; i < size_b; ++i) cin >> b[i];
        
        
        for(int i = 0; i < size_a; ++i){
            for(int j = 0; j < size_b; ++j){
                t[i+j] += a[i]*b[j];
            }
        }
        
        for(int i = 0; i < size_a+size_b-1; ++i) cout << t[i] << " ";
        cout << endl;
        
    }
	return 0;
}