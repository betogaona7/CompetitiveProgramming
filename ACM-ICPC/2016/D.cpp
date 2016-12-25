#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    long long N,n;
    long double x;
    do
    {
        cin>>N;
        if(N==0)
            break;
        else
        {
            n=N/2;
            if(N%2==0)
            {
                
                x=((2*n-1)*(2*n)*(2*n+1))/6;
                x=sqrt(x*2/(N-1));

            }
            else
            {
            	x=0;
                for(int a=1, b=2;a<=n;a++,b+=2)
                	x+=pow(b,2);
                x=sqrt(x*2/(N-1));
            }
            printf("%.6Lf\n",x);

        }
    }while(1);
    return 0;

}

