
#include<bits/stdc++.h>
using namespace std;



int dfs(vector<vector<int>> g,vector<int>& vis,int root,vector<int>& col,int c)
{


    vis[root] = 1;
    col[root] = c;
  //  cout<<root<<" ";
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
            int x = dfs(g,vis,g[root][i],col,c^1);
            if(x == 0)
                return 0;
        }
        else{


            if(col[g[root][i]] == c)
            {
                return 0;
            }

        }



    }
    return 1;




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
    vector<int> col(v);
    for(int i = 0;i < v;i++)
    {
        vis[i] = 0;
    }
    ///dfs start

    if(dfs(g,vis,0,col,0)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }











    return 0;
}

