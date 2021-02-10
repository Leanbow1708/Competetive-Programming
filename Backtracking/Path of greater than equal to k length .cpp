
#include<bits/stdc++.h>
using namespace std;
int adj[20][20];
vector<int> vis(20);
int k,v;

bool dfs(int n,int count){

    vis[n] = 1;

    if(count >= k)
    return 1;
    bool ans = 0;
    for(int i = 0;i < v;i++)
    {
        if(vis[i] == 0 && adj[n][i] != 0)
        {
            ans =  ans|dfs(i,count+adj[n][i]);

        }



    }



    vis[n] = 0;
    return ans;

}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {


        int e;
        cin>>v>>e>>k;



        for(int i =0;i < v;i++)
        {
            for(int j = 0;j < v;j++)
            {
                adj[i][j] = 0;
            }
        }



        for(int i = 1;i <= e;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            adj[a][b] = w;
            adj[b][a] = w;

        }


         for(int i = 0;i <20;i++)
                vis[i] = 0;

        bool ans = 0;
        /// starting is always from 0
         ans = dfs(0,0);


        if(ans == 1)
            cout<<1;
        else
            cout<<0;
        cout<<endl;



    }


    return 0;
}
