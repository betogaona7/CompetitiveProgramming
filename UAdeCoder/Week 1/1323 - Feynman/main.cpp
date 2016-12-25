#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n), n != 0){

        int answer = (n*(n+1))*(2*n+1);
        cout<< answer/6 <<endl;

    }
    return 0;
}
