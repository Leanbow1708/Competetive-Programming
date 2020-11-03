#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int a[n];
    int t[n+1];
    memset(t,0,sizeof(t));

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];

        t[a[i]]++;

    }
    for(int i = 0;i <= n;i++)
    {
        if(t[i] > 0)
        {
            t[i]--;
            cout<<i<<" ";
            i--;

        }

    }






    return 0;
}
