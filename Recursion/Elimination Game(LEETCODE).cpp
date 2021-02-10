#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& v,int turn){
    if(v.size() == 1)
    {
        return v[0];
    }
    int t = 0;
    int d = 0;
    if(turn == 0)
    {
        if(v.size() % 2 == 0)
        {
            d++;
            t = 1;
        }
        else{
            t = 0;
        }
    }
    auto it = v.begin();

    int n = v.size();
    for(int i = 0;i < n;i++)
    {
        if(i % 2 == t)
        {
            v.erase(it+d);
            d++;
        }



    }

   return fun(v,turn^1);






}


int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i = 0;i < n;i++)
    {
        v[i] = i+1;
    }

    cout<<fun(v,1);


    return 0;
}
