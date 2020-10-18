#include<bits/stdc++.h>
#define ll long long
using namespace std;



ll fun(char* s,int n,ll* ans)
{

    if(ans[n] == -1)
    {

        if(s[n-1] == '0')
    {
        return fun(s,n-2,ans);

    }
    if(n == 0 || n == 1)
        return 1;
    ll a = fun(s,n-1,ans);
    ll b = 0;
        if(s[n-2] == '0')
        {

            return a;
        }
        else{

            int x = (s[n-2]-48)*10+(s[n-1]-48);
            if(x <= 26)
            {
                b = fun(s,n-2,ans);

            }


        }
        ans[n] = a+b;
    }
    return ans[n];




}
int main()
{

char s[5005];
ll ans[5005];

    while(1)
    {
        memset(ans,-1,sizeof(ans));
        ans[0] = ans[1] = 1;


        scanf("%s",s);
      //  cout<<s;
        int n = strlen(s);

        if(s[0] == '0')
            break;
        ll x = fun(s,n,ans);
        printf("%lld\n",x);





    }







    return 0;
}
