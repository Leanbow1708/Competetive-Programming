#include<bits/stdc++.h>
using namespace std;

vector<bool> prime(100000);
vector<int> dis(100000);
vector<int> vis(100000);
vector<vector<int>> adj(100000);



void fill_prime(){

    for(int i = 0;i <= 9999;i++)
    {
        prime[i] = 0;
    }

    for(int i = 1000;i <= 9999;i++)
    {
        int flag = 1;
        for(int j = 2;j <=sqrt(i);j++)
        {
            if(i % j == 0)
            {
                flag = 0;
                prime[i] = 0;
                break;
            }
        }
        if(flag == 1)
        {
            prime[i] = 1;
        }



    }


}

int can_connect(int a,int b){

    int count = 0;
    while(a > 0)
    {
        if(a%10 != b%10)
        {
            count++;
        }
        a = a/10;
        b = b/10;
    }

    if(count == 1)
        return 1;
    return 0;



}

void make_graph(){

    for(int i = 1000;i <= 9999;i++)
    {
        if(prime[i] == 1)
        {
            for(int j = i+1;j <= 9999;j++)
                {
                    if(prime[j] == 1)
                    {
                        if(can_connect(i,j))
                        {
                            adj[i].push_back(j);
                            adj[j].push_back(i);

                        }

                    }

                }

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
        fill_prime();
        make_graph();
        int t;
        cin>>t;
        while(t--)
        {
            for(int i = 1000;i <= 9999;i++)
            {
                dis[i] = -1;
                vis[i] = 0;
            }

            int root,dest;
            cin>>root>>dest;
            bfs(root);
            if(dis[dest] == -1)
            {
                cout<<"Impossible";
            }
            else{
                cout<<dis[dest];
            }
            cout<<endl;



        }





}
