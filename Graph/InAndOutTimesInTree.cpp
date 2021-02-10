#include<bits/stdc++.h>
using namespace std;

int t;


void dfs(vector<vector<int>> g,vector<int>& vis,int root,vector<int>& in,vector<int>& out)
{


    vis[root] = 1;

    in[root] = t;

    //cout<<root<<" ";
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
            t++;
            dfs(g,vis,g[root][i],in,out);
        }
    }

    t++;
    out[root] = t;




}

int main()
{
    t++;
    int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    vector<int> in(v);
    vector<int> out(v);

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

    dfs(g,vis,0,in,out);
    for(int i = 0;i < v;i++)
    {
        cout<<in[i]<<" "<<out[i]<<endl;
    }











    return 0;
}


