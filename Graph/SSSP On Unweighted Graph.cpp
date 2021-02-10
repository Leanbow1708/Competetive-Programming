#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adj(1000);
vector<int> vis(1000);

int main()
{
    int v,e;
    cin>>v>>e;

    for(int i = 0;i < e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

      vector<int> dis(v);
    for(int i = 0;i < v;i++)
    {
        dis[i] = 0;
        vis[i] = 0;
    }
    vector<int> ans;


    queue<int> q;
    int root = 2;

    q.push(root);
    vis[root] = 1;
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
                dis[adj[n][i]] = 1 + dis[n];

            }
        }
    }

    for(int i = 0;i < ans.size();i++)
    {
        cout<<dis[i]<<" ";
    }








    return 0;
}

