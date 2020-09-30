#include<bits/stdc++.h>
using namespace std;
int main()
{


    int n,m;
    cin>>n>>m;
    int p[n+1];
    memset(p,0,sizeof(p));
    while(m--)
    {

        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        for(int i = l;i <= r;i++)
        {
            if(p[i] == 0 && i != x)
            {
                p[i] = x;

            }

        }
   }

   for(int i = 1;i <= n;i++)
   {

   printf("%d ",p[i]);
      // cout<<p[i]<<" ";
   }



    return 0;
}
