#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>> g,vector<int>& vis,int root)
{


    vis[root] = 1;
    cout<<root<<" ";
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
            dfs(g,vis,g[root][i]);
        }
    }




}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i = 1;i <= e;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> vis(v);
    for(int i = 0;i < v;i++)
    {
        vis[i] = 0;
    }
    ///dfs start

    dfs(g,vis,0);










    return 0;
}

