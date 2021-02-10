#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1000);
vector<int> vis(1000);
vector<int> sub(1000);

int dfs(int node){

    vis[node] = 1;
    int sum = 1;
    for(int i = 0;i < adj[node].size();i++)
    {
        if(vis[adj[node][i]] == 0)
        {
            sum += dfs(adj[node][i]);
        }

    }
    sub[node] = sum;
    return sum;




}




int main()
{
    int v;
    cin>>v;

    for(int i = 0;i < v-1;i++)
    {
        cin>>a>>b;
        int a,b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 0;i < v;i++)
    {
        vis[i] = 0;
        sub[i] = 0;
    }
    dfs(0);

    for(int i = 0;i < v;i++)
    {
        cout<<sub[i]<<" ";
    }








    return 0;
}
