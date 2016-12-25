#include <iostream>

using namespace std;

int main()
{
    int n;
    double number;
    cin >> n;

    while(n--){
        int cont = 0;
        cin >> number;
        while(number > 1){
            number /= 2;
            cont += 1;
        }

        cout << cont << " dias"<<endl;
    }
    return 0;
}
