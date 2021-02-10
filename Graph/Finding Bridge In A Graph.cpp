#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1000);
vector<int> vis(1000);

vector<int> in(1000);
vector<int> low(1000);
int timer = 0;


void dfs(int root,int parent){

    vis[root] = 1;
    in[root] = timer;
    low[root] = timer;
    timer++;

    for(int i = 0;i < adj[root].size();i++)
    {
        if(adj[root][i] == parent)
            continue;

        if(vis[adj[root][i]] == 0)
        {
            dfs(adj[root][i],root);

            if(in[root] < low[adj[root][i]])
            {


                cout<<root<<" -> "<<adj[root][i]<<endl;

            }
            low[root] = min(low[root],low[adj[root][i]]);

        }
        else{

            low[root] = min(low[root],in[adj[root][i]]);

        }


    }




}



int main()
{
    int v,e;
    cin>>e;
    for(int i = 0;i < e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,1);


    return 0;
}
