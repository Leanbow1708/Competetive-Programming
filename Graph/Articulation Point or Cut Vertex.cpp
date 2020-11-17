#include<bits/stdc++.h>
using namespace std;

vector<int> vis(100);
vector<int> in(100);
vector<int> low(100);
vector<vector<int>> adj(100);
int count1 = 0;


void dfs(int root,int parent){

    vis[root] = 1;
    in[root] = count1;
    low[root] = count1;
    count1++;

    int tree = 0;
    for(int i = 0;i < adj[root].size();i++)
    {
        if(adj[root][i] != parent)
        {
        if(vis[adj[root][i]] == 1)
        {
            low[root] = min(low[root],in[adj[root][i]]);
        }
        else{

            dfs(adj[root][i],root);
            if(in[root] <= low[adj[root][i]]){
                    if(parent == -1)
               tree++;
            else
               cout<<root<<"is an articulation point"<<endl;
            }
            low[root] = min(low[root],low[adj[root][i]]);


        }
        }

    }


    if(parent == -1 && tree > 1)
    {
        cout<<root<<" is an articulation point";
    }

}


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
    dfs(1,-1);






    return 0;
}
