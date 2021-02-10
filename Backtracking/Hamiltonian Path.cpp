#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adj(20);
vector<int> vis(20);
int v;

bool dfs(int n,int count){

    vis[n] = 1;
    count++;
    if(v == count)
    return 1;
    bool ans = 0;
    for(int i = 0;i < adj[n].size();i++)
    {
        if(vis[adj[n][i]] == 0)
        {

        ans = ans | dfs(adj[n][i],count);

        }

    }
    vis[n] = 0;
    return ans;

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i = 0;i < 20;i++)
        {
            adj[i].clear();
        }

        int e;
        cin>>v>>e;
        for(int i = 1;i <= e;i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }


         for(int i = 0;i <20;i++)
                vis[i] = 0;

        bool ans = 0;
        for(int i = 1;i <= v;i++)
        {
            ans = ans|dfs(i,0);


            for(int j = 0;j <20;j++)
                vis[j] = 0;




        }
        if(ans == 1)
            cout<<1;
        else
            cout<<0;
        cout<<endl;



    }


    return 0;
}
