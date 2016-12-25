#include <iostream>
#include<cstdio>
int main()
{
    int n=0,m=0,q=0,i=0,j=0,z=0;
    while(scanf("%d",&n)!=EOF)
    {
        int slot[n];
        for(int u=0;u<n;u++)
        	slot[u]=0;

        scanf("%d",&m);
        for(int r=m;r>0;r--)
        {

        	scanf("%d",&q);
        	if(q==0)
        	{
        		scanf("%d %d",&i,&z);
        		slot[i]=z;
        	}
        	if(q==1)
        	{
        		int cont=0;
        		scanf("%d %d %d",&i,&j,&z);
        		for(int x=i;x<=j;x++)
        		{
        			if(slot[x]<=z)
        				cont++;
        		}
        		printf("%d\n",cont);
        	}

        }
    }
    return 0;
}
