
#include<bits/stdc++.h>
using namespace std;



    vector<int> vis(1000000);




void dfs(vector<vector<int>> g,vector<int>& vis,int root)
{


    vis[root] = 1;
    //cout<<root<<" ";
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
  //  scanf("%d%d",&v,&e);
    vector<vector<int>> g(v+1);
    for(int i = 1;i <= e;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ///dfs start

    int count = 0;

     dfs(g,vis,1);
     count++;
     for(int i = 1;i <= v;i++)
     {
         if(vis[i] == 0)
         {
             count++;
         }
     }



    if(count == 1 && e == v-1)
    {
        cout<<"YES";
       // printf("YES");

    }else{
        cout<<"NO";
   // printf("NO");
    }












    return 0;
}

