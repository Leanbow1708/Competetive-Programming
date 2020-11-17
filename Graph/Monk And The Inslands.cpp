#include<bits/stdc++.h>
using namespace std;



int main()
{
    int t;
    cin>>t;
    while(t--)
    {

    int v,e;
    cin>>v>>e;


    vector<vector<int>> adj(v+1);
    vector<int> vis(v+1);

    for(int i = 0;i < e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

      vector<int> dis(v+1);
    for(int i = 1;i <= v;i++)
    {
        dis[i] = 0;
        vis[i] = 0;
    }



    queue<int> q;
    int root = 1;

    q.push(root);
    vis[root] = 1;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();

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

    cout<<dis[v]<<endl;





    }



    return 0;
}

