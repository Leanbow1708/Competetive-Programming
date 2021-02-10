#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    set<int> s;
    for(int i = 1;i<=n;i++)
    {
        s.insert(i);

    }
    int p[n+1];
    memset(p,0,sizeof(p));
    while(m--)
    {


        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        auto it = s.lower_bound(l);

        vector<int> toErase;
        auto start = s.begin();
        while(it != s.end() &&*it <= r)
            {
                if(*it != x)
                {
                    p[*it] = x;
                     toErase.push_back(*it);

                }

                it++;


            }
            for(auto it = toErase.begin();it != toErase.end();it++)
            {

                s.erase(*it);
            }




    }
    for(int i = 1;i <= n;i++)
    {

        printf("%d ",p[i]);
    }



}
