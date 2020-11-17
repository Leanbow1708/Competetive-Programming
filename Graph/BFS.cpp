#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adj(1000);
vector<int> vis(1000);

int main()
{
    int v,e;
    cin>>v;

    for(int i = 0;i < e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0;i < v;i++)
    {
        vis[i] = 0;
    }
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        ans.push_back(n);
        for(int i = 0;i < adj[n].size();i++)
        {
            if(vis[adj[n][i]] == 0)
            {
                vis[adj[n][i]] = 1;
                q.push(adj[n][i]);

            }
        }
    }

    for(int i = 0;i < ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }








    return 0;
}
