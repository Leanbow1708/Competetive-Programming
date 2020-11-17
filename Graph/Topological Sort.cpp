#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(1000);
vector<int> res;
int in[1000];


void kahn(int v){

///res.clear();
    queue<int>q;
    for(int i = 1;i <= v;i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        res.push_back(n);
        for(int i = 0;i < adj[n].size();i++)
        {
            in[adj[n][i]]--;
            if(in[adj[n][i]] == 0)
                q.push(adj[n][i]);
        }




    }



}

int main()
{
    memset(in,0,sizeof(in));

    int v,e;
    cin>>v>>e;
    for(int i = 0;i < e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    kahn(v);///kahn's algo for topological sort
    for(int i = 0;i < res.size();i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}
