#include<bits/stdc++.h>
#define clear(a) memset(a,0,sizeof(a))
using namespace std;

vector<int>number[1000001];

int main()
{

    int m, n, k, v;
    while(scanf("%d %d",&m,&n) != EOF)
    {
        clear(number);
        int x;
        for(int i = 1; i <= m; i++)
        {
           cin>>x;
           number[x].push_back(i);
        }

        for(int i = 0; i < n; i++)
        {
            cin >> k >> v;
            if(k > number[v].size())
                cout<< 0 << endl;
            else
                cout<<number[v][k -1] << endl;
        }
    }
    return 0;
}
