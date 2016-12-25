#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, t;
    //int cells[];
    cin >> n >> t;

    int cells[n-1];

    for(int i = 1; i < n; i++){
        scanf("%d", &cells[i]);
    }

    for(int i = 1; i <= n; i+= cells[i]){
        if(i == t){
            cout << "YES" <<endl;
            return 0;
        }
    }
    cout << "NO" <<endl;

    return 0;
}
