#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>> g,vector<int>& vis,int root,int d,vector<int>& dis)
{

    dis[root] = d+1;

    vis[root] = 1;
    //cout<<root<<" ";
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
            dfs(g,vis,g[root][i],dis[root],dis);
        }
    }




}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v+1);
    for(int i = 1;i <= e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(v+1);
    vector<int> dis(v+1);
    for(int i = 0;i <= v;i++)
    {
        vis[i] = 0;
    }
    ///dfs start

    dfs(g,vis,2,-1,dis);

    for(int i = 1;i <= v;i++)
    {
        cout<<dis[i]<<" ";
    }












    return 0;
}

