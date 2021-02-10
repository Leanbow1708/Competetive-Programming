#include<bits/stdc++.h>
using namespace std;
string res = "";


void fun(string s,int k)
{
    if(k == 0)
    {

        res = max(res,s);
        return;
    }
     int n = s.size();
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {

            swap(s[i],s[j]);
            fun(s,k-1);
            swap(s[i],s[j]);
        }
    }



}


void solve(){

    string s;
    int k;
    cin>>s>>k;

    int n = s.size();
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {

            swap(s[i],s[j]);
            fun(s,k-1);
            swap(s[i],s[j]);
        }
    }


}

int main()
{
    solve();
    cout<<res;
    return 0;
}
