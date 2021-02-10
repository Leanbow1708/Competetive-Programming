#include<bits/stdc++.h>
using namespace std;



int dfs(vector<vector<int>> g,vector<int>& vis,int root,int pre)
{


    vis[root] = 1;
   // cout<<root<<" ";
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
           int x = dfs(g,vis,g[root][i],root);
           if(x == 1)
           {
               return 1;
           }
        }
        else{

            if(g[root][i] != pre)
            {
                return 1;
            }

        }
    }
        return 0;



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


    for(int i = 0;i < v;i++)
    {
        if(vis[i] == 0)
        {
          int x = dfs(g,vis,i,-1);
       if(x == 1)
       {
           cout<<"Contains Cycle";
           return 0;
       }

        }



    }

    cout<<"No Cycle Detected";










    return 0;
}

