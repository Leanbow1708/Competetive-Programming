#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

        int n;
        scanf("%d",&n);
        ll a[n];
        ll temp[n];
        for(int i = 0;i < n;i++)
            temp[i] = 1;
        //memset(temp,1,sizeof(temp));
        for(int i = 0;i < n;i++)
        {

            scanf("%lld",&a[i]);
        }
        for(int i = 1;i < n;i++)
        {
            for(int j = i - 1;j >= 0;j--)
            {
                if(a[i] > a[j])
                {
                    temp[i] = max(temp[i],1+temp[j]);

                }

            }



        }

        ll temp_max = INT_MIN;
        for(int i = 0;i < n;i++)
        {

       // cout<<temp[i]<<" ";
            temp_max = max(temp_max,temp[i]);
        }
        printf("%lld\n",temp_max);










    return 0;
}
