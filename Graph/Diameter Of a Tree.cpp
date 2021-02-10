#include<bits/stdc++.h>
using namespace std;

int max_dis;
int node;
vector<vector<int>> g(10001);
vector<int> vis(10001);

void dfs(int root,int dist)
{


    if(dist > max_dis){
            max_dis = dist;
    node = root;

    }
    vis[root] = 1;
    for(int i = 0;i < g[root].size();i++)
    {

        if(vis[g[root][i]] == 0)
        {
            dfs(g[root][i],dist+1);
        }
    }




}

int main()
{


    max_dis = INT_MIN;




    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int v,e;
   // scanf("%d",&v);
    cin>>v;
    e = v-1;

    for(int i = 1;i <= e;i++)
    {
        int a,b;
      //  scanf("%d%d",&a,&b);
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    for(int i = 0;i < v;i++)
    {
        vis[i] = 0;
    }
    ///dfs start

    dfs(0,0);



    max_dis = INT_MIN;

    for(int i = 0;i < v;i++)
    {
        vis[i] = 0;
    }
    dfs(node,0);


   // printf("%d",node_max);
    cout<<max_dis;









    return 0;
}


