#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll fun(int i,int j,int n,int m)
{

    ll total = (n*m)%mod;

    int count = 0;

    ///UUL
    if(i-2>=0 && j-1>=0)
        count++;
    ///UUR
    if(i-2>=0 && j+1<m)
        count++;
    ///ULL
    if(i-1>=0 && j-2>=0)
        count++;
    ///URR
    if(i-1>=0 && j+2<m)
        count++;
    ///DDL
    if(i+2<n && j-1>=0)
        count++;
    ///DDR
    if(i+2<n && j+1<m)
        count++;
    ///DLL
    if(i+1<n && j-2>=0)
        count++;
    ///DRR
    if(i+1<n && j+2<m)
        count++;
    count++;
    return (total-count);




}

ll solve(){
    int n,m;
    cin>>n>>m;
    ll count = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            ll ways = fun(i,j,n,m);

            count = (count+ways)%mod;


        }
    }

    return count;
}


int main()
{
    cout<< solve();


    return 0;
}
