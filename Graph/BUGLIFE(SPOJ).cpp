

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

    int t;
    int x = 1;
    scanf("%d",&t);
    while(x <= t)
    {
        int v,e;
    cin>>v>>e;
    vector<vector<int>> g(v);
    for(int i = 1;i <= e;i++)
    {
        int a,b;
        cin>>a>>b;
        ///here we are doing a--,b-- because we r numbering them from 0 not 1
        a--;
        b--;
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


    printf("Scenario #%d:\n",x);
    x++;

    int temp = 1;

    for(int i = 0;i < v;i++)
    {
        if(vis[i] == 0)
        {
             if(dfs(g,vis,i,col,0)){}
    else{
            temp = 0;
            break;
    }

        }


    }


    if(temp == 1){

       printf("No suspicious bugs found!\n");
       // cout<<"YES";
    }
    else{
            printf("Suspicious bugs found!\n");
        //cout<<"NO";
    }


















    }








    return 0;
}

