#include<bits/stdc++.h>
#define m 1000000007
using namespace std;

int dfs(vector<vector<int>>& g,vector<int>& vis,int root,int count)
{

    count++;
    vis[root] = 1;
    //cout<<root<<" ";
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
           int x = dfs(g,vis,g[root][i],0);
           count += x;
        }
    }

        return count;


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
   // scanf("%d",&t);
    while(t--){
        int v,e;
   // scanf("%d%d",&v,&e);
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
    for(int i = 0;i <= v;i++)
    {
        vis[i] = 0;
    }
    ///dfs start

    int count = 0;
    long long ways = 1;
    for(int i = 1;i <= v;i++)
    {
        if(vis[i] == 0)
        {

            count++;
           long long temp =  dfs(g,vis,i,0);

           ways = (ways*temp)%m;

        }

    }
    cout<<count<<" "<<ways<<'\n';

   /// printf("%d %d\n",count,ways);





    }







    return 0;
}

