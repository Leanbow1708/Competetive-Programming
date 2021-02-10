#include<bits/stdc++.h>
using namespace std;

int adj[25][25];
int vis[25];
int c[25];
int temp = 0;
/// c[i] -> it represents that for ith vertex which numbered color is used
int v,e,m;

bool dfs(int node)
{
    vis[node] = 1;

    /// here we will check that which colors its adjacent vertices have used
    int color[m] = {0};
    for(int i = 0;i < m;i++)
        color[i] = 0;

    for(int i = 0;i < v;i++)
    {
        /// look for childs
        if(adj[node][i] == 1)
        {
            if(vis[i] == 1)
            {

                color[c[i]] = 1;
            }

        }

    }
    bool ans = 0;

    for(int i = 0;i < m;i++)
    {
        if(color[i] == 0)
        {

            for(int j = 0;j < v;j++)
            {

                if(adj[node][j] == 1 && vis[j] == 0)
                {

                    temp++;
                    c[node] = i;
                    ans = dfs(j);
                    temp--;
                    c[node] = -1;
                    if(ans == 1)
                        return 1;
                }
            }



        }


    }
    if(temp == v-1)
    {
        /// we are at last node now and we haven't assigned color to it;
        int color[m] = {0};
        for(int i = 0;i < v;i++)
        {
            if(adj[node][i] == 1)
            {

                color[c[i]] = 1;
            }

        }
        for(int i = 0;i < m;i++)
        {
            if(color[i] == 0)
                return 1;
        }


    }

    vis[node] = 0;
    return 0;




}


void solve(){

    for(int i = 0;i <25;i++)
    {
        vis[i] = 0;
        c[i] = -1;
        for(int j = 0;j < 25;j++)
            adj[i][j] = 0;

    }
    /// adj[a][b] = 1 means there is an edge 0 means there is no direct edge
    for(int i = 0;i < e;i++)
    {

        int a,b;
        cin>>a>>b;
        adj[a-1][b-1] = 1;
        adj[b-1][a-1] = 1;

    }

    bool ans = 0;


    for(int i = 0;i < v;i++)
    {

        ans = ans|dfs(i);


    }
    cout<<ans;


}


int main()
{

    cin>>v>>e>>m;
    solve();
    return 0;
}
