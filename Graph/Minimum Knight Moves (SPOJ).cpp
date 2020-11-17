#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adj(100);
vector<int> vis(100);
vector<int> dis(100);

void make_move(char c,int i,int j){

    int root = 10*i + j;
    if(c == 'U')
    {
        if(i+2 <= 8)
        {
            if(j+1 <= 8)
            {
                int n1 = (i+2)*10 + j+1;
                adj[root].push_back(n1);
            }
            if(j-1 >= 1)
            {
                int n1 = (i+2)*10 + j-1;
                adj[root].push_back(n1);
            }
        }




    }
    else if(c == 'D'){

         if(i-2 >= 1)
        {
            if(j+1 <= 8)
            {
                int n1 = (i-2)*10 + j+1;
                adj[root].push_back(n1);
            }
            if(j-1 >= 1)
            {
                int n1 = (i-2)*10 + j-1;
                adj[root].push_back(n1);
            }
        }

    }
    else if(c == 'L')
    {

         if(j-2 >= 1)
        {
            if(i+1 <= 8)
            {
                int n1 = (i+1)*10 + j-2;
                adj[root].push_back(n1);
            }
            if(i-1 >= 1)
            {
                int n1 = (i-1)*10 + j-2;
                adj[root].push_back(n1);
            }
        }
    }
    else if(c == 'R')
    {

         if(j+2 <= 8)
        {
            if(i+1 <= 8)
            {
                int n1 = (i+1)*10 + j+2;
                adj[root].push_back(n1);
            }
            if(i-1 >= 1)
            {
                int n1 = (i-1)*10 + j+2;
                adj[root].push_back(n1);
            }
        }
    }







}



void make_graph(){

    for(int i = 1;i <= 8;i++)
    {
        for(int j = 1;j <= 8;j++)
        {

            make_move('U',i,j);
            make_move('D',i,j);
            make_move('L',i,j);
            make_move('R',i,j);

        }
    }



}

void bfs(int root){


    dis[root] = 0;
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();
        for(int i = 0;i < adj[n].size();i++)
        {
            if(vis[adj[n][i]] == 0)
            {
                vis[adj[n][i]] = 1;
                q.push(adj[n][i]);
                dis[adj[n][i]] = 1 + dis[n];

            }
        }
    }




}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    make_graph();

    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int root = (s1[0]-'a'+1)*10 + s1[1]-'0';
        int dest = (s2[0]-'a'+1)*10 + s2[1]-'0';


        for(int i = 0;i < 100;i++)
        {
            vis[i] = 0;
            dis[i] = 0;
        }
        bfs(root);
        cout<<dis[dest]<<endl;







    }




    return 0;
}
